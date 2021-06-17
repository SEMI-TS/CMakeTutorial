#Project 이름으로 아래 이름으로 실행 파일이 생성 됩니다.
project(Helloword) 

#cmake의 버전이 최소한 아래의 버전 이상이 필요 하다는 의미 입니다.
cmake_minimum_required (VERSION 3.5)

#set 키워드는 환경 변수를 선언 하는 명령어 인데요 아래와 같이 
#SRC_FILE를 명시적으로 선언 해주어야 합니다.
# *.cpp *.c 로 사용 할 수도 있는데요 
# 위와 같이 사용 할 경우 예기치 않는 오류가 발생 할 수도 있기 때문에
#  제가 추천 드리는 방법은 명시적으로 빌드 할 파일을 지정 하는 방법 입니다.

set(SRC_FILE 
            helloword.cpp
            )

# 아래의 옵션은 SRC_FILE을 빌드 후 PROJECT_NAME('Helloword') 이름으로 실행 할수 
# 있는 파일을 만드는 옵션 입니다.
add_executable(${PROJECT_NAME} ${SRC_FILE})

# 아주 간단한 예제이기 때문에 4줄 정도로 CMake List 파일을 작성 완료 했습니다.
