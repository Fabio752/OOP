Triangle.class: Triangle.java
	javac Triangle.java

Point.class: Point.java
	javac Point.java

Main.class: Main.java
	javac Main.java


all: Point.java FarthestPoint.java Main.java
	javac *.java
	

run: Main.class
	java Main


clean:
	rm *.class 


compile: Point.java Triangle.java Main.java Main.class
	javac *.java
	java Main

