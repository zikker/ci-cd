FROM drogonframework/drogon:latest

WORKDIR /app

RUN apt-get update && \
    apt-get install -y libgtest-dev cmake && \
    cd /usr/src/gtest && \
    cmake . && \
    make && \
    cp lib/*.a /usr/lib

COPY . .

RUN mkdir build
WORKDIR /app/build
RUN cmake .. && cmake --build .

EXPOSE 8080

CMD ["./MyDrogonApp"]