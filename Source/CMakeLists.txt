file(GLOB_RECURSE application_source 
	./**.cpp 
	./**.c 
	./**.h)

add_executable(CPPPerformance 
	${application_source}
)