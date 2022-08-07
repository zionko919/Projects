 Ver. 2.0 Upadate
 I passed in the vector so that it can find out
 the position of each planets. Then my program calculates the velocity
 based on the force being acted on. the step functions moves the planets
 accordingly, as they should rotate the sun counter-clockwise. 
 	1. The program shows the elapsed time.
 	2. The program plays the 2001.wav bgm.

Ver. 1.0 
 This program will display a static universe from
 getting datas from the planets.txt file.
 I also did the extra credit so mine shows the background. 

 The main program first reads in the number of planets. 
 Then it reads in the radius of the universe. 
 Then it reads values for the x and y coordinates and initializes the planets. 
 It then initializes by setting the texture from actual files, 
 then having sprite texture to the newly made texture. 
 The important bit is that every time sprites redraw themselves, 
 the program recalculates the sprite's position based on the window 
 size that I have set to 600, then displays the sprites on the window.

 I used shared pointer to created my vector in Universe class in my header file. 
 ex1) vector<shared_ptr<CelestialBody>> universe;
 Then, I created an object using a shared pointer in my main file, 
 and put make_shared pointer value from CelestialBody class.
 ex2) shared_ptr<CelestialBody> newPlanet = make_shared<CelestialBody>(CelestialBody(window_size, radius));
