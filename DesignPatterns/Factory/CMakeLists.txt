cmake_minimum_required(VERSION 3.10)
project(factory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(factory
    main.cpp
    EmailNotification.cpp
    SMSNotification.cpp
    NotificationFactory.cpp
) 
