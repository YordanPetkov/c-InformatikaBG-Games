if(
       s[0].x>2 && s[0].y>1 && s[0].x<=20 && s[0].y<20 &&
       !CanHere((s[0].x)-2,s[0].y) && Table[(s[0].x)-2][s[0].y]!=LastMe && Table[(s[0].x)-2][s[0].y]!=LastHe &&
        !CanHere(s[0].x-1,s[0].y-1) && Table[s[0].x-1][s[0].y-1]!=LastMe && Table[s[0].x-1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x-1,s[0].y+1) && Table[s[0].x-1][s[0].y+1]!=LastMe && Table[s[0].x-1][s[0].y+1]!=LastHe &&
       CanUp(s[0].x,s[0].y)
       ){Table[s[0].x-1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>0 && s[0].y>1 && s[0].x<=16 && s[0].y<20 &&
       !CanHere(s[0].x+2,s[0].y) && Table[s[0].x+2][s[0].y]!=LastMe && Table[s[0].x+2][s[0].y]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y-1) && Table[s[0].x+1][s[0].y-1]!=LastMe && Table[s[0].x+1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y+1) && Table[s[0].x+1][s[0].y+1]!=LastMe && Table[s[0].x+1][s[0].y+1]!=LastHe &&
       CanDown(s[0].x,s[0].y)
       ){Table[s[0].x+1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>1 && s[0].y>2 && s[0].x<20 && s[0].y<=20 &&
       !CanHere(s[0].x,s[0].y-2) && Table[s[0].x][s[0].y-2]!=LastMe && Table[s[0].x][s[0].y-2]!=LastHe &&
       !CanHere(s[0].x-1,s[0].y-1) && Table[s[0].x-1][s[0].y-1]!=LastMe && Table[s[0].x-1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y-1) && Table[s[0].x+1][s[0].y-1]!=LastMe && Table[s[0].x+1][s[0].y-1]!=LastHe &&
       CanLeft(s[0].x,s[0].y)
       ){Table[s[0].x][s[0].y-1]='$';PosMoves--;}


    if(
       s[0].x>1 && s[0].y>0 && s[0].x<20 && s[0].y<=18 &&
       !CanHere(s[0].x,s[0].y+2) && Table[s[0].x][s[0].y+2]!=LastMe && Table[s[0].x][s[0].y+2]!=LastHe &&
       !CanHere(s[0].x-1,s[0].y+1) && Table[s[0].x-1][s[0].y+1]!=LastMe && Table[s[0].x-1][s[0].y+1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y+1) && Table[s[0].x+1][s[0].y+1]!=LastMe && Table[s[0].x+1][s[0].y+1]!=LastHe &&
       CanRight(s[0].x,s[0].y)
       ){Table[s[0].x][s[0].y+1]='$';PosMoves--;}

      char BefA='A'-1,Befa='a'-1;
    if(
       s[0].x>3 && s[0].y>1 && s[0].x<=20 && s[0].y<20 &&
        !CanHere(s[0].x-1,s[0].y-1) && Table[s[0].x-1][s[0].y-1]!=LastMe && Table[s[0].x-1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x-1,s[0].y+1) && Table[s[0].x-1][s[0].y+1]!=LastMe && Table[s[0].x-1][s[0].y+1]!=LastHe &&
        CanUp(s[0].x,s[0].y) &&
       !CanHere((s[0].x)-3,s[0].y) && Table[(s[0].x)-3][s[0].y]!=LastMe-BefA+'A' && Table[(s[0].x)-3][s[0].y]!=LastHe-Befa+'a' &&
        !CanHere(s[0].x-2,s[0].y-1) && Table[s[0].x-2][s[0].y-1]!=LastMe-BefA+'A' && Table[s[0].x-2][s[0].y-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x-2,s[0].y+1) && Table[s[0].x-2][s[0].y+1]!=LastMe-BefA+'A' && Table[s[0].x-2][s[0].y+1]!=LastHe-Befa+'a' &&
       CanUp(s[0].x-1,s[0].y)
       ){Table[s[0].x-1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>0 && s[0].y>1 && s[0].x<=17 && s[0].y<20 &&
        !CanHere(s[0].x+1,s[0].y-1) && Table[s[0].x+1][s[0].y-1]!=LastMe && Table[s[0].x+1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y+1) && Table[s[0].x+1][s[0].y+1]!=LastMe && Table[s[0].x+1][s[0].y+1]!=LastHe &&
       CanDown(s[0].x,s[0].y) &&
       !CanHere((s[0].x)+3,s[0].y) && Table[(s[0].x)+3][s[0].y]!=LastMe-BefA+'A' && Table[(s[0].x)+3][s[0].y]!=LastHe-Befa+'a' &&
        !CanHere(s[0].x+2,s[0].y-1) && Table[s[0].x+2][s[0].y-1]!=LastMe-BefA+'A' && Table[s[0].x+2][s[0].y-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+2,s[0].y+1) && Table[s[0].x+2][s[0].y+1]!=LastMe-BefA+'A' && Table[s[0].x+2][s[0].y+1]!=LastHe-Befa+'a' &&
       CanDown(s[0].x+1,s[0].y)
       ){Table[s[0].x+1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>1 && s[0].y>3 && s[0].x<20 && s[0].y<=20 &&
       !CanHere(s[0].x-1,s[0].y-1) && Table[s[0].x-1][s[0].y-1]!=LastMe && Table[s[0].x-1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y-1) && Table[s[0].x+1][s[0].y-1]!=LastMe && Table[s[0].x+1][s[0].y-1]!=LastHe &&
       CanLeft(s[0].x,s[0].y) &&
       !CanHere((s[0].x),s[0].y-3) && Table[(s[0].x)][s[0].y-3]!=LastMe-BefA+'A' && Table[(s[0].x)][s[0].y-3]!=LastHe-Befa+'a' &&
        !CanHere(s[0].x-1,s[0].y-2) && Table[s[0].x-1][s[0].y-2]!=LastMe-BefA+'A' && Table[s[0].x-1][s[0].y-2]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+1,s[0].y-2) && Table[s[0].x+1][s[0].y-2]!=LastMe-BefA+'A' && Table[s[0].x+1][s[0].y-2]!=LastHe-Befa+'a' &&
       CanLeft(s[0].x,s[0].y-1)
       ){Table[s[0].x][s[0].y-1]='$';PosMoves--;}

    if(
       s[0].x>1 && s[0].y>=1 && s[0].x<20 && s[0].y<=17 &&

       !CanHere(s[0].x-1,s[0].y+1) && Table[s[0].x-1][s[0].y+1]!=LastMe && Table[s[0].x-1][s[0].y+1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y+1) && Table[s[0].x+1][s[0].y+1]!=LastMe && Table[s[0].x+1][s[0].y+1]!=LastHe &&
       CanRight(s[0].x,s[0].y) &&

        !CanHere((s[0].x),s[0].y+3) && Table[(s[0].x)][s[0].y+3]!=LastMe-BefA+'A' && Table[(s[0].x)][s[0].y+3]!=LastHe-Befa+'a' &&
        !CanHere(s[0].x-1,s[0].y+2) && Table[s[0].x-1][s[0].y+2]!=LastMe-BefA+'A' && Table[s[0].x-1][s[0].y+2]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+1,s[0].y+2) && Table[s[0].x+1][s[0].y+2]!=LastMe-BefA+'A' && Table[s[0].x+1][s[0].y+2]!=LastHe-Befa+'a' &&
       CanRight(s[0].x,s[0].y+1)
       ){Table[s[0].x][s[0].y+1]='$';PosMoves--;}

       char BefA2='A'-2,Befa2='a'-2;
    if(
       s[0].x>4 && s[0].y>1 && s[0].x<=20 && s[0].y<20 &&
        !CanHere(s[0].x-1,s[0].y-1) && Table[s[0].x-1][s[0].y-1]!=LastMe && Table[s[0].x-1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x-1,s[0].y+1) && Table[s[0].x-1][s[0].y+1]!=LastMe && Table[s[0].x-1][s[0].y+1]!=LastHe &&
        CanUp(s[0].x,s[0].y) &&
        !CanHere(s[0].x-2,s[0].y-1) && Table[s[0].x-2][s[0].y-1]!=LastMe-BefA+'A' && Table[s[0].x-2][s[0].y-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x-2,s[0].y+1) && Table[s[0].x-2][s[0].y+1]!=LastMe-BefA+'A' && Table[s[0].x-2][s[0].y+1]!=LastHe-Befa+'a' &&
       CanUp(s[0].x-1,s[0].y) &&
       !CanHere((s[0].x)-4,s[0].y) && Table[(s[0].x)-4][s[0].y]!=LastMe-BefA2+'A' && Table[(s[0].x)-4][s[0].y]!=LastHe-Befa2+'a' &&
        !CanHere(s[0].x-3,s[0].y-1) && Table[s[0].x-3][s[0].y-1]!=LastMe-BefA2+'A' && Table[s[0].x-3][s[0].y-1]!=LastHe-Befa2+'a' &&
       !CanHere(s[0].x-3,s[0].y+1) && Table[s[0].x-3][s[0].y+1]!=LastMe-BefA2+'A' && Table[s[0].x-3][s[0].y+1]!=LastHe-Befa2+'a' &&
       CanUp(s[0].x-2,s[0].y)
       ){Table[s[0].x-1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>0 && s[0].y>1 && s[0].x<=16 && s[0].y<20 &&
        !CanHere(s[0].x+1,s[0].y-1) && Table[s[0].x+1][s[0].y-1]!=LastMe && Table[s[0].x+1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y+1) && Table[s[0].x+1][s[0].y+1]!=LastMe && Table[s[0].x+1][s[0].y+1]!=LastHe &&
       CanDown(s[0].x,s[0].y) &&
        !CanHere(s[0].x+2,s[0].y-1) && Table[s[0].x+2][s[0].y-1]!=LastMe-BefA+'A' && Table[s[0].x+2][s[0].y-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+2,s[0].y+1) && Table[s[0].x+2][s[0].y+1]!=LastMe-BefA+'A' && Table[s[0].x+2][s[0].y+1]!=LastHe-Befa+'a' &&
       CanDown(s[0].x+1,s[0].y)
        &&
       !CanHere((s[0].x)+4,s[0].y) && Table[(s[0].x)+4][s[0].y]!=LastMe-BefA2+'A' && Table[(s[0].x)+4][s[0].y]!=LastHe-Befa2+'a' &&
        !CanHere(s[0].x+3,s[0].y-1) && Table[s[0].x+3][s[0].y-1]!=LastMe-BefA2+'A' && Table[s[0].x+3][s[0].y-1]!=LastHe-Befa2+'a' &&
       !CanHere(s[0].x+3,s[0].y+1) && Table[s[0].x+3][s[0].y+1]!=LastMe-BefA2+'A' && Table[s[0].x+3][s[0].y+1]!=LastHe-Befa2+'a' &&
       CanDown(s[0].x+2,s[0].y)
       ){Table[s[0].x+1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>1 && s[0].y>4 && s[0].x<20 && s[0].y<=20 &&
       !CanHere(s[0].x-1,s[0].y-1) && Table[s[0].x-1][s[0].y-1]!=LastMe && Table[s[0].x-1][s[0].y-1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y-1) && Table[s[0].x+1][s[0].y-1]!=LastMe && Table[s[0].x+1][s[0].y-1]!=LastHe &&
       CanLeft(s[0].x,s[0].y) &&
        !CanHere(s[0].x-1,s[0].y-2) && Table[s[0].x-1][s[0].y-2]!=LastMe-BefA+'A' && Table[s[0].x-1][s[0].y-2]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+1,s[0].y-2) && Table[s[0].x+1][s[0].y-2]!=LastMe-BefA+'A' && Table[s[0].x+1][s[0].y-2]!=LastHe-Befa+'a' &&
       CanLeft(s[0].x,s[0].y-1)&&
       !CanHere((s[0].x),s[0].y-4) && Table[(s[0].x)][s[0].y-4]!=LastMe-BefA2+'A' && Table[(s[0].x)][s[0].y-4]!=LastHe-Befa2+'a' &&
        !CanHere(s[0].x-1,s[0].y-3) && Table[s[0].x-1][s[0].y-3]!=LastMe-BefA2+'A' && Table[s[0].x-1][s[0].y-3]!=LastHe-Befa2+'a' &&
       !CanHere(s[0].x+1,s[0].y-3) && Table[s[0].x+1][s[0].y-3]!=LastMe-BefA2+'A' && Table[s[0].x+1][s[0].y-3]!=LastHe-Befa2+'a' &&
       CanLeft(s[0].x,s[0].y-2)
       ){Table[s[0].x][s[0].y-1]='$';PosMoves--;}

    if(
       s[0].x>1 && s[0].y>=1 && s[0].x<20 && s[0].y<=16 &&

       !CanHere(s[0].x-1,s[0].y+1) && Table[s[0].x-1][s[0].y+1]!=LastMe && Table[s[0].x-1][s[0].y+1]!=LastHe &&
       !CanHere(s[0].x+1,s[0].y+1) && Table[s[0].x+1][s[0].y+1]!=LastMe && Table[s[0].x+1][s[0].y+1]!=LastHe &&
       CanRight(s[0].x,s[0].y) &&

        !CanHere(s[0].x-1,s[0].y+2) && Table[s[0].x-1][s[0].y+2]!=LastMe-BefA+'A' && Table[s[0].x-1][s[0].y+2]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+1,s[0].y+2) && Table[s[0].x+1][s[0].y+2]!=LastMe-BefA+'A' && Table[s[0].x+1][s[0].y+2]!=LastHe-Befa+'a' &&
       CanRight(s[0].x,s[0].y+1)

        &&

        !CanHere((s[0].x),s[0].y+4) && Table[(s[0].x)][s[0].y+4]!=LastMe-BefA2+'A' && Table[(s[0].x)][s[0].y+4]!=LastHe-Befa2+'a' &&
        !CanHere(s[0].x-1,s[0].y+3) && Table[s[0].x-1][s[0].y+3]!=LastMe-BefA2+'A' && Table[s[0].x-1][s[0].y+3]!=LastHe-Befa2+'a' &&
       !CanHere(s[0].x+1,s[0].y+3) && Table[s[0].x+1][s[0].y+3]!=LastMe-BefA2+'A' && Table[s[0].x+1][s[0].y+3]!=LastHe-Befa2+'a' &&
       CanRight(s[0].x,s[0].y+2)
       ){Table[s[0].x][s[0].y+1]='$';PosMoves--;}
