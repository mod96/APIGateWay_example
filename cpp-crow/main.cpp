#include "crow_all.h"

#include "boj_16236.h"

int main()
{
    crow::SimpleApp app; // define your crow application

    // define your endpoint at the root directory
    CROW_ROUTE(app, "/")
    ([]()
     { return "Hello world!"; });

    // To see it in action, I recommend to use the Postman Chrome extension:
    //      * Set the address to {ip}:8080/add_json
    //      * Set the method to post
    //      * Select 'raw' and then JSON
    //      * Add {"a": 1, "b": 1}
    //      * Send and you should receive 2
    CROW_ROUTE(app, "/add_json")
        .methods("POST"_method)([](const crow::request &req)
                                {
          auto x = crow::json::load(req.body);
          if (!x)
              return crow::response(400);
          int sum = x["a"].i() + x["b"].i();
          std::ostringstream os;
          os << sum;
          return crow::response{os.str()}; });

    // To see it in action, I recommend to use the Postman Chrome extension:
    //      * Set the address to {ip}:8080/boj/16236/solve
    //      * Set the method to post
    //      * Select 'raw' and then JSON
    //      * Add {"N": 4, "arr": [[4, 3, 2, 1], [0, 0, 0, 0], [0, 0, 9, 0], [1, 2, 3, 4]]}
    //      * Send and you should receive 14
    CROW_ROUTE(app, "/boj/16236/solve")
        .methods("POST"_method)([](const crow::request &req)
                                {
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);

        int n = x["N"].i();
        int arr[20][20];
        crow::json::rvalue temp = x["arr"];
        std::vector<crow::json::rvalue> rows = temp.lo();
        for (int i = 0; i < n; i++) {
            std::vector<crow::json::rvalue> row = rows.at(i).lo();
            for (int j = 0; j < n; j++) {
                arr[i][j] = row.at(j).i();
            }
        }
        boj_16236::Solver SolutionClass(n, arr);
        std::ostringstream os;
        os << SolutionClass.solve();
        return crow::response{os.str()}; });

    // crow::request req;
    // crow::response res;
    // std::unique_ptr<crow::routing_handle_result> found;
    // req.method = crow::HTTPMethod::Post;
    // req.url = "/boj/16236/solve";
    // req.body = "{\"N\": 4, \"arr\": [[4, 3, 2, 1], [0, 0, 0, 0], [0, 0, 9, 0], [1, 2, 3, 4]]}";
    // app.handle(req, res, found);
    // std::cout << res.body << std::endl;
    // set the port, set the app to run on multiple threads, and run the app
    app.port(8080).multithreaded().run();
}
