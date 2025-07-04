FROM drogonframework/drogon:latest

WORKDIR /app

COPY CMakeLists.txt .
COPY main.cpp .
COPY palindrome.cpp .
COPY palindrome.h .
COPY test ./test

RUN mkdir build
WORKDIR /app/build
RUN cmake ..
RUN cmake --build .


EXPOSE 8080

CMD ["./MyDrogonApp"]
