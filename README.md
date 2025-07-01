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

#### Socket 통신
- 소켓 통신은 이더넷 기반 실시간 데이터 전송방식인 TCP/UDP를 사용하는 양방향 통신

#### TCP/IP 프로토콜 구조
- 네트워크 계층 : 물리적 네트워크를 통한 실제 데이터 송수신 
    - 장치 드라이버, 네트워크 하드웨어
- 인터넷 계층 : 네트워크 계층의 도움을 받아 데이터를 목적지 호스트까지 전달하는 역할
    - IP
- 전송 계층 : 최종 통신 목적지를 지정하고 오류없이 데이터를 전송하는 역할
    - TCP, UDP
- 응용 계층 : 전송계층을 기반으로 하는 다수의 프로토콜과 이 프로토콜을 사용하는 응용 프로그램을 포괄
    - TELNET, FTP, HTTP, SMTP, MIME, SNMP, ...


#### 서버
- 소켓 생성 - socket()
- 소켓 주소 할당 - bind()
- 연결요청 대기 - listen()
- 연결허용 - accept()
- 데이터 송/수신 - read/write()
- 연결 종료 - close()

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

#### 소켓 주소 구조체
- 네트워크 통신에 필요한 주소를 담는 구조체
- 다양한 소켓 함수의 인수로 전달하여 사용
- sockaddr : 대표타입, 소켓 함수의 인수타입으로 사용
- sockaddr_in, sockaddr_in6: 각각 IPv4, IPv6프로토콜에서 사용

#### 바이트 정렬방식
- 빅 에디언(Big-endian)     큰 값부터 저장(AMD)
- 리틀에디언(Little-endian) 작은 값부터 저장(INTEL)

- 바이트 변환 함수
    - unsigned short htons(unsigned short);     h -> n(short)
    - unsigned short ntohs(unsigned short);     n -> h(ushort)
    - unsigned long htonl(unsigned long);       n -> n(ulong)
    - unsigned long ntohl(unsigned long);       n -> h(ulong)

    - htons(), htonl() : 호스트 바이트 정렬 -> 네트워크 바이트 정렬
    - ntohs(), ntohl() : 네트워크 바이트 정렬 -> 호스트 바이트 정렬

#### 파일 열기/닫기

- 오픈모드
    |오픈모드||
    |:--|:--|
    |O_CREAT|필요하면 파일을 생성|
    |O_TRUNC|기존 데이터 전부 삭제|
    |O_APEND|기존 데이터 보존하고, 이어서 저장|
    |O_RDONLY|읽기 전용으로 파일 오픈|
    |O_WRONLY|쓰기 전용으로 파일 오픈|
    |O_RDWR|읽기, 쓰기 겸용으로 파일 오픈|

#### IP 주소 변환 함수
- inet_pton() : 문자열 -> 숫자(네트워크 바이트 정렬)
- inet_ntop() : 숫자(네트워크 바이트 정렬) -> 문자열
- inet_addr() : 문자열 -> 숫자(네트워크 바이트 정렬)
- inet_ntoa() : 숫자(네트워크 바이트 정렬) -> 문자열

#### TCP 서버 클라이언트 핵심 동작
1. 서버는 먼저 실행하여 클라이언트가 접속하기를 기다린다(listen)
2. 클라이언트는 서버에 접속(connect)하여 데이터를 보낸다(send)
3. 서버는 클라이언트 접속을 수용하고(accept), 클라이언트가 보낸 데이터를 받아서(recv)처리한다.
4. 서버는 처리한 데이터를 클라이언트에 보낸다(send)
5. 클라이언트는 서버가 보낸 데이터를 받아서(recv) 처리한다.
6. 데이터를 주고받는 과정을 모두 마치면 접속을 끊는다(closesocket/close).


## 3일차

## 4일차

## 5일차