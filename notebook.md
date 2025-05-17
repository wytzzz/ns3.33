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

# 环境变量
export QUICHE_SRC_DIR=/usr/network/quiche/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QUICHE_SRC_DIR/build/:/usr/network/ns-allinone-3.33/ns-3.33/build/lib/
export DQC=/usr/network/ns-allinone-3.33/ns-3.33/src/dqc/model/thirdparty  
export PATH=/usr/bin:$PATH


## 编译ns3
- 设置QUICHE_SRC_DIR 
export QUICHE_SRC_DIR=/usr/network/quiche/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QUICHE_SRC_DIR/build/
export DQC=/usr/network/ns-allinone-3.33/ns-3.33/src/dqc/model/

- config
参考: https://www.cnblogs.com/zywnnblog/p/13049146.html
CXXFLAGS="-std=c++17 -Wno-error -g" ./waf configure

- build
bear ./waf build

- 编译错误
c++: fatal error: Killed signal terminated program cc1plus
compilation terminated.
解决: 减少编译线程数

- 创建.clangd
"settings": {
	"clangd.path": "/usr/bin/clangd",
	"clangd.arguments": [
		"--compile-commands-dir=. -I./build"
	],
}	
# 测试
- 运行
./waf --run "scratch/bbr-var-eva-3.26 --it=1 --cc=bbr"  

- 日志收集

- 绘制


# 版本差异
3.33以后, 
 pointToPoint.SetQueue ("ns3::DropTailQueue",
                           "MaxSize", StringValue (std::to_string(5)+"p"));

													 







