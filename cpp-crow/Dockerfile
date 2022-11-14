# get baseimage
FROM gcc:12

EXPOSE 8080

# copy files from local folder to destination
COPY . /usr/src

# define working directory in container
WORKDIR /usr/src

# compile main.cpp (-I/usr/src/asio/ link path starting from root)
RUN g++ -I/usr/src/asio/ main.cpp -lpthread -o app

# run executable
CMD [ "./app" ]