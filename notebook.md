# 编译

## 编译quiche
apt-get install cmake build-essential protobuf-compiler libprotobuf-dev golang-go libunwind-dev libicu-dev  

- 在quiche目录中: 
cd quiche  
mkdir build && cd build  
cmake ..  
make
编译出.so和.a

- 创建证书
cd quiche/util  
chmod 777 generate-certs.sh  
./generate-certs.sh   
mkdir -p data/quic-cert  
mv ./out/*  data/quic-cert/  

## 编译ns3
- 设置QUICHE_SRC_DIR 
sudo gedit /etc/profile  
export QUICHE_SRC_DIR=/home/xxx/quiche/  
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QUICHE_SRC_DIR/build/  

- config
参考: https://www.cnblogs.com/zywnnblog/p/13049146.html
CXXFLAGS="-std=c++17 -Wno-error" ./waf configure

- build
bear ./waf build

- 编译错误
c++: fatal error: Killed signal terminated program cc1plus
compilation terminated.
解决: 减少编译线程数

- 创建.clangd
CompileFlags:
  Add: 
    - -I/Users/bytedance/workspace/network/quiche/
    - -I/Users/bytedance/workspace/network/ns-allinone-3.33/ns-3.33/build












