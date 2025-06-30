# iot-network-2025
loT  네트워크 프로그래밍 리포지토리 2025

## 1일차

#### 필요한 설치
- VMware-workstation-full-17.6.3-24583834.exe download
- ubuntu.com 
    - Ubuntu 24.04.2 LTS download
- VMware Workstation에 Ubuntu 설치

- vmware 가상머신 만들기
    - custom -> 빈칸에 ubuntu
    
#### TCP/IP 프로토콜 개요 
- 정보를 요구하는 쪽이 클라이언트 제공하는 쪽이 서버

#### TCP/IP 프로토콜 구조
- 네트워크 계층 : 물리적 네트워크를 통한 실제 데이터 송수신 
    - 장치 드라이버, 네트워크 하드웨어
- 인터넷 계층 : 네트워크 계층의 도움을 받아 데이터를 목적지 호스트까지 전달하는 역할
    - IP
- 전송 계층 : 최종 통신 목적지를 지정하고 오류없이 데이터를 전송하는 역할
    - TCP, UDP
- 응용 계층 : 전송계층을 기반으로 하는 다수의 프로토콜과 이 프로토콜을 사용하는 응용 프로그램을 포괄
    - TELNET, FTP, HTTP, SMTP, MIME, SNMP, ...


#### 소켓의 개념
- 소켓 생성 - socket()
- 소켓 주소 할당 - bind()
- 연결요청 대기 - listen()
- 연결허용 - accept()
- 데이터 송/수신 - read/write()
- 종료 - close()

#### 기본 실행
- uname -a : 정보확인
- cd : 폴더이동
- ls : 현재 폴더를 보여준다
- pwd : 현재 위치
- cd.. : 전단계로 이동
- ./ : 현재 폴더
- mkdir : 폴더 생성
- clear : 화면 지움
- rm -fr : 파일/폴더 삭제
- touth : 빈파일 생성
- cat : 화면에 출력 
- cp : 복사
- sudo nano /etc/nacorc : nano 설정
- sudo apt install gcc : gcc 컴파일러 설치
- ./xxx : 실행 명령

#### IPv4 인터넷 주소의 체계
- 클래스 A  네트워크ID(1)+ 호스트ID(3)  0 ~ 127 이하 (0)
- 클래스 B  네트워크ID(2)+ 호스트ID(2)  128 ~ 191 (10)
- 클래스 C  네트워크ID(3)+ 호스트ID(1)  192 ~ 223 (110)
- 클래스 D  

#### 프로토콜 체계
- PF_INET   IPv4 인터넷 프로토콜 체계
- PF_INET6  IPv6 인터넷 프로토콜 체계

#### 소케의 타입(전송 방식)
- TCP(연결지향형 소켓) - SOCK_STREAM
- UDP(비연결지향형 소켓) - SOCK_DGRAM

## 2일차

## 3일차

## 4일차

## 5일차