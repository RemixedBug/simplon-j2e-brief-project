FROM gcc:10.2.0
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -std=c++20 -o myapp main.cpp
CMD ["./myapp"] 
