# Milionaire
## _Ai là triệu phú_


Ai là triệu phú là 1 project của môn Lập trình mạng IT4062

## Features

- Đăng ký, đăng nhập, đổi mật khẩu
- Chơi 1 mình
- Chơi PvP

## Tech

Project sử dụng:
- C/C++: Ngôn ngữ dùng để xử lý phía BackEnd
- QML: Ngôn ngữ FrontEnd của Client
- Qt Framework 5.12
- MySQL: Lưu trữ tài khoản và câu hỏi

## Installation Qt

Project sử dụng [Qt Framework](https://www.qt.io/) v5.12.8 để chạy

Cài đặt Qt trên Ubuntu 20.04 hoặc cài đặt phiên bản 5.12.8 trên trang chủ của [Qt](https://www.qt.io/)

```sh
sudo apt install qt5-default
sudo apt-get install qtdeclarative5-dev qml-module-qtquick-controls qml-module-qtquick2 qml-module-qtquick-layouts qml-module-qtgraphicaleffects
sudo apt install qml-module-qtquick-controls2
sudo apt-get install qml-module-qtquick-dialogs
sudo apt-get install qml-module-qtmultimedia

```
## để kiểm tra các module đã được cài đặt hay chưa, có thể truy cập vào Files->Other locations->Computer->usr->lib->x86_64-linux-gnu->qt5->qml
## Run Project
##### _1. Clone Project_ #####

```sh
git clone https://github.com/Luvannie/AiLaTrieuPhu-1.git
cd AiLaTrieuPhu
```

#### _2. Server_ ####

##### 2.1. Cài đặt MYSQL Server, library Dev MySQL #####
```sh
sudo apt install mysql-server libmysqlclient-dev
```

##### 2.2. Config file config và import database.sql #####

##### 2.3. Run Server #####

```sh
cd server/
make
./server <PORT>
```

#### _3. Client_ ####

##### 3.1. Install Lib GL #####

```sh
sudo apt install libgl1-mesa-dev
```

##### 3.2. Run Client #####

```sh
cd client/
qmake
make install
./client <ip server> <port>
```
