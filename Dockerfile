FROM drogonframework/drogon:latest

WORKDIR /app

COPY CMakeLists.txt .
COPY main.cpp .

RUN mkdir build
WORKDIR /app/build
RUN cmake ..
RUN cmake --build .


EXPOSE 8080

ENTRYPOINT ["./MyDrogonApp"]