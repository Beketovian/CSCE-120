#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;
//static int _maxRow = 0;
//static int _maxCol = 0;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {

    ifstream inputfile(fileName);
    //if file not valid
    if(!inputfile.is_open()){return nullptr;}
    //row
    inputfile >> maxRow;
    if(inputfile.fail() || maxRow > 999999 || maxRow <= 0){return nullptr;}
    //_maxRow = maxRow;
    //col 
    inputfile >> maxCol;
    if(inputfile.fail() || maxCol > 999999 || maxRow <= 0){return nullptr;}
    //_maxCol = maxCol;
    //player row
    inputfile >> player.row;
    if(inputfile.fail() || player.row > 999999 || player.row < 0 || maxRow <= 0 || player.row > maxRow){return nullptr;}
    //player col
    inputfile >> player.col;
    if(inputfile.fail() || player.col > 999999 || player.col < 0 || maxCol <= 0 || player.col > maxCol){return nullptr;}
    //check for hidden
    if(maxRow >= INT32_MAX/maxCol || maxCol >= INT32_MAX/maxRow){return nullptr;}

    //check for if player position isn't in map
    if(player.row >= maxRow || player.col >= maxCol){return nullptr;}   

    char** map = createMap(maxRow,maxCol);

    //if not load
    if(map == nullptr)
    {
        deleteMap(map, maxRow);
        return nullptr;
    }

    int rct = 0;
    int cct = 0;
    for(int i = 0; i < maxRow; i++)
    {
        rct++;
        for(int j = 0; j < maxCol; j++)
        {
            inputfile >> map[i][j];
            if(i == player.row && j == player.col)
            {
                map[i][j] = TILE_PLAYER;
            }
            if(map[i][j] != TILE_AMULET && map[i][j] != TILE_DOOR && map[i][j] != TILE_EXIT && map[i][j] != TILE_MONSTER && map[i][j] != TILE_OPEN && map[i][j] != TILE_PILLAR && map[i][j] != TILE_PLAYER && map[i][j] != TILE_TREASURE)
            {
                deleteMap(map, maxRow);
                return nullptr;
            }
            cct++;
        }
    }
    //cout << maxRow << rct << maxCol << " "<< cct/rct;
    if(rct != maxRow || cct/rct != maxCol)
    {
        deleteMap(map, maxRow);
        return nullptr;
    }

    //check for every TILE and if there is door or exit
    bool door = false;
    bool exit = false;

    for(int i = 0; i < maxRow; i++)
    {
        for(int j = 0; j < maxCol; j++)
        {
            if(map[i][j] == TILE_DOOR){door = true;}
            else
            {
                if(map[i][j] == TILE_EXIT){exit = true;}
            }
        }
    }
    if(!door && !exit)
    {
        deleteMap(map,maxRow);
        return nullptr;
    }
    

    inputfile.close();
    return map;
}

//aranzazu bravo cerpa de mi corazon uno

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if(input == MOVE_UP)
    {
        if(nextRow != 0)
        {
            nextRow--;
        }
    }

    if(input == MOVE_DOWN)
    {
        // if(nextRow != _maxRow-1)
        // {
            nextRow++;
        //}
    }

    if(input == MOVE_LEFT)
    {
        if(nextCol != 0)
        {
            nextCol--;
        }
    }

    if(input == MOVE_RIGHT)
    {
        // if(nextCol != _maxCol-1)
        // {
            nextCol++;
       // }    
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {

    char** map = new char*[maxRow];

    for(int i = 0; i < maxRow; i++)
    {
        //each col in row
        map[i] = new char[maxCol];
        for(int j = 0; j < maxCol; j++)
        {
            map[i][j] = TILE_OPEN;
        }
    }
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map != nullptr){
    for(int i = 0; i < maxRow; i++){delete[] map[i];}
    delete[] map;
    map = nullptr;
    }
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    //if map or invalid maxrow/maxcol
    if(map == nullptr){return nullptr;}
    if(maxRow < 1 || maxCol < 1){return nullptr;}
    //check for resized map max
    if(maxRow*2 > INT32_MAX/(maxCol*2)){return nullptr;}
    if(maxCol*2 > INT32_MAX/(maxRow*2)){return nullptr;}

    //player position
    int player_row;
    int player_col;
    for(int i = 0; i < maxRow; i++)
    {
        for(int j = 0; j < maxCol; j++)
        {
            if(map[i][j] == TILE_PLAYER)
            { 
                player_row = i;
                player_col = j;
                map[i][j] = TILE_OPEN;
            }
        }
    }

    int colc = 0;
    int rowc = 0;

    int orow = maxRow;
    int ocol = maxCol;
    maxRow = maxRow * 2;
    maxCol = maxCol * 2;


    char** newmap = new char*[maxRow];

    for(int i = 0; i < maxRow; i++)
    {
        newmap[i] = new char[maxCol];
        for(int j = 0; j < maxCol; j++)
        {
            if(rowc >= orow){rowc = 0;}
            if(colc >= ocol){colc = 0;}
            newmap[i][j] = map[rowc][colc];
            colc += 1;
        }
        rowc += 1;
    }
    //put player back
    newmap[player_row][player_col] = TILE_PLAYER;
    deleteMap(map, orow);
    //new global maxrow and maxcol
    //_maxRow = maxRow;
    //_maxCol = maxCol;
    return newmap;    
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    //check out of bounds (no move)
    
    if(nextRow > maxRow-1 || nextCol > maxCol-1 || nextRow < 0 || nextCol < 0)
    {
        nextRow = player.row;
        nextCol = player.col;
        return STATUS_STAY;
    }
    char next_tile = map[nextRow][nextCol];
    //check tile or monster (no move)
    if(next_tile == TILE_MONSTER || next_tile == TILE_PILLAR)
    {
        nextRow = player.row;
        nextCol = player.col;
        return STATUS_STAY; 
    }
    //move if open
    if(next_tile == TILE_OPEN)
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_MOVE;
    }
    //amulet
    if(next_tile == TILE_AMULET)
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_AMULET;
    }
    //door
    if(next_tile == TILE_DOOR)
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_LEAVE;
    }
    //treasure
    if(next_tile == TILE_TREASURE)
    {
        player.treasure += 1;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_TREASURE;
    }
    //exit
    if(next_tile == TILE_EXIT)
    {
        if(player.treasure > 0)
        {
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
            return STATUS_ESCAPE;
        }
        else
        {
            nextRow = player.row;
            nextCol = player.col;
            return STATUS_STAY;
        }
    }

    return 0;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    //check above
    for(int i = player.row-1; i >= 0; i--)
    {
        //if pillar above
        if(map[i][player.col] == TILE_PILLAR){break;}
        if(map[i][player.col] == TILE_MONSTER)
        {
            map[i+1][player.col] = TILE_MONSTER;
            map[i][player.col] = TILE_OPEN;
            //break;      
        }
    }
    //check below
    for(int i = player.row+1; i < maxRow; i++)
    {
        //if pillar below
        if(map[i][player.col] == TILE_PILLAR){break;}
        if(map[i][player.col] == TILE_MONSTER)
        {
            map[i-1][player.col] = TILE_MONSTER;
            map[i][player.col] = TILE_OPEN;
            //break;      
        }
    }
    //check left
    for(int i = player.col-1; i >=0; i--)
    {
        //if pillar left
        if(map[player.row][i] == TILE_PILLAR){break;}
        if(map[player.row][i] == TILE_MONSTER)
        {
            map[player.row][i+1] = TILE_MONSTER;
            map[player.row][i] = TILE_OPEN;
            //break;      
        }
    }
    //check right
    for(int i = player.col+1; i < maxCol; i++)
    {
        //if pillar right
        if(map[player.row][i] == TILE_PILLAR){break;}
        if(map[player.row][i] == TILE_MONSTER)
        {
            map[player.row][i-1] = TILE_MONSTER;
            map[player.row][i] = TILE_OPEN;
            //break;      
        }
    }
    //if monster on us
    if(map[player.row][player.col] == TILE_MONSTER){return true;}
    //return false if not
    return false;
}
