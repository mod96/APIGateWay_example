FROM gcc:12-bullseye AS base

COPY . /usr/src
WORKDIR /usr/src

# compile main.cpp (-I/usr/src/asio/ link path starting from root)
RUN g++ -I/usr/src/asio/ *.cpp -lpthread -o app

FROM base AS development
CMD [ "bash", "-c", "./app" ]

FROM debian:bullseye-slim AS production
EXPOSE 8080
COPY --from=base /usr/src/ /usr/src
CMD [ "bash", "-c", "./app" ]
