FROM gcc:latest
WORKDIR /usr/src/app
COPY task8_2.cpp .
RUN g++ -o battle task8_2.cpp
CMD ["./battle"]
