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

### Once the blocks have checked because this method is intensive it should be written to a new array and those will have the blocks that will be drawed <br> When a block is broken or something is changed there should be, as minecraft calls it a "chunk update" this redos the chunk check and updates the array that draws the cubes accordinly

### For chunks next to each other and on the same y level you could remove the inner part of that side and keep the outer so it does not draw 384 extra cubes <br> This would not work though if the chunk y level is on different levels so a other fix should be found <br> Getting the surrounding chunk and getting the cubes that are next from the chunk right next is the way <br> Have another check that gets from a cental chunk the 6 chunks surrounding it and gets their position arrays and performs <br> Get each side of the chunk and get the opposite side on the other chunk and check the positions with those positions

### sides of chunk are in cords (scaled by whatever the size of the chunk is)
#### front is 0,0,0 to 1,1,0 (x,y incresing)
#### right is 1,0,0 to 1,1,1 (y,z incresing)
#### back is 1,0,1 to 0,1,1 (x decresing, y incresing)
#### left is 0,0,1 to 0,1,0 (y incresing, z decresing)
#### top is 0,1,0 to 1,1,1 (x,z incresing)
#### bottom is 0,0,0 to 1,0,1 (x,z incresing)


### psudeo code
    for every cube position //find a better way to do this like getting the positions visable
        if(cube has position on all sides)
            dont draw
        else
            draw the cube


## Pointer vectors (i hate it i hate it i hate it)
### to access a variable or method from one do (*vector)[index].something
### if it is a vector in another vector then do (*vector->vector)[index]