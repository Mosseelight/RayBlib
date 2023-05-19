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