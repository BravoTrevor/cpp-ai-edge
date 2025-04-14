FROM arm64v8/ubuntu:20.04  
RUN apt-get update && apt-get install -y git cmake g++  
COPY . /app  
WORKDIR /app/build  
RUN cmake .. -DUSE_OPENBLAS=ON && make  
CMD ["./bin/inference"]  