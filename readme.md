# Wsl stuff
### When vscode is open to compile from the terminal in vscode run
## wsl make home/phillip/Documents/Codes/RayBlib/

## Steps for wsl
### run the bat script
### run gnome-session
### in terminal in xserver run code Documents/Codes/RayBlib
## Done

# Have to restart vscode for source control to see the change
# Do all changes then push beacuse after push vscode needs a restart

# Random code things

## color by positon
    int y = 0;
    int x = 0;

    if(y < SCREENHEIGHT)
    {
        for (int x = 0; x < SCREENWIDTH; x++)
        {
            auto r = double(x) / (SCREENWIDTH-1);
            auto g = double(y) / (SCREENHEIGHT-1);
            auto b = 0.25;

            u_char ir = 255.999 * r;
            u_char ig = 255.999 * g;
            u_char ib = 255.999 * b;
            DrawPixel(x,y, Color{ir, ig, ib, 255});
        }
        y++;
    }

## cube culling
### since minecraft checks if it should render the cube if there is a air block <br> and since i dont want to create air blocks <br>  we can check to see if all sides have a cube next to it <br> and not draw if true

### Once the blocks have checked because this method is intensive it should be written to a new array and those will have the blocks that will be draw <br> When a block is broken is something is changed there should be, as minecraft calls it a "chunk update" this redos the chunk check and updates the array that draws the cubes accordinly


### psudeo code
    for every cube position //find a better way to do this like getting the positions visable
        if(cube has position on all sides)
            dont draw
        else
            draw the cube