#Project 이름으로 아래 이름으로 실행 파일이 생성 됩니다.
project(Helloword) 

#cmake의 버전이 최소한 아래의 버전 이상이 필요 하다는 의미 입니다.
cmake_minimum_required (VERSION 3.5)
find_package(HellowLib REQUIRED)

include(GNUInstallDirs)

set(SRC_FILE 
            src/helloword.cpp
            )

add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME} HellowLib)