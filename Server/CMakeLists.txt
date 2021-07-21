cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")
set(CMAKE_CXX_STANDARD 11)

set(SRC
	src/main.cpp

	src/Common.h

	src/Logging.cpp
	src/Logging.h

	src/GameServer.cpp
	src/GameServer.h

	src/Settings.cpp
	src/Settings.h

	# Network
	src/Network/NetworkManager.cpp
	src/Network/NetworkManager.h

	# Entities
	src/Entities/Player.cpp
	src/Entities/Player.h
	src/Entities/Vehicle.cpp
	src/Entities/Vehicle.h

	# World
	src/World/World.cpp
	src/World/World.h

	src/World/Entity.cpp
	src/World/Entity.h

	src/World/Queries/Range.cpp
	src/World/Queries/Range.h
)

set(SHARED_SRC
	../Shared/SharedUtils.h
	../Shared/RefCounted.h
	../Shared/Octree.h
	../Shared/Enums/NetworkMessageType.h
	../Shared/Network/NetworkMessage.h
	../Shared/Network/NetHandle.h
	../Shared/Network/NetworkEntityType.h
	../Shared/Network/Structs/CreatePed.h
	../Shared/Network/Structs/CreateVehicle.h
)

add_executable(Server
	${SRC}
	${SHARED_SRC}
)

source_group(TREE "${CMAKE_SOURCE_DIR}/src/" PREFIX Src FILES ${SRC})
source_group(TREE "${CMAKE_SOURCE_DIR}/../Shared/" PREFIX Shared FILES ${SHARED_SRC})

find_package(ENet REQUIRED)

target_link_libraries(Server
	${ENet_LIBRARIES}
)

if(WIN32)
	target_link_libraries(Server
		Ws2_32
		WinMM
	)
endif()

include_directories(
	${CMAKE_SOURCE_DIR}/src
	${ENet_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/../Libs/glm
	${CMAKE_SOURCE_DIR}/../Shared
)
