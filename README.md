
<S개발자 과제1>
32 bit 숫자가 파일에 4바이트의 크기로 저장되어 있다(network byte order). 
2개의 파일로부터 숫자를 읽어 들여 그 합을 출력하는 프로그램을 작성하라.




-조건
1. 프로그램의 argument를 명시하지 않은 경우.       
   => fopen을 통해 포인터로 파일을 열고 그 포인터 변수가 null일 때 error를 출력    
2. argument로 넘어온 파일이 존재하지 않거나 파일 열기에 실패하는 경우.         
   => fread를 통해 file1, file2를 모두 and 연산자로 읽고 둘 중 하나라도 읽을 수 없을 경우(참이 아니라면) 즉 and 연산자 값이 1이 아닐 경우 error 출력      
3. 파일의 크기가 32bit(4바이트보다) 작아서 제대로 읽을 수 없는 경우.  
   => 2와 마찬가지로 while문 안에서 4바이트로 sizeof(uint32_t) 만큼 읽을 수 없다면 읽기에 실패해서 error 출력






+Makefile      
    >cmake 이용해서 생성     
    >CMakeLists.txt 최소 옵션 명시    
    
    # CMakeLists.txt    
      cmake_minimum_required(VERSION 3.24)    
      project(add-nbo)     
 
      add_executable(add-nbo add-nbo.c)    
