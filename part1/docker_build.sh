docker build -t w2-gtest:0.1 .
docker run -ti -v `pwd`:/test w2-gtest:0.1 bash -c "cd /test ; g++ -std=c++11 main.cpp"