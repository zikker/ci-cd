FROM drogonframework/drogon:latest

WORKDIR /app

COPY . .

RUN mkdir build
WORKDIR /app/build
RUN cmake ..
RUN cmake --build .


EXPOSE 8080

CMD ["./MyDrogonApp"]
