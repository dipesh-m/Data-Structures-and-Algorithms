class Solution {
public:
    int getNeighbourAliveCount(int i, int j, int WORLD_HEIGHT, int WORLD_WIDTH, vector<vector<int>>& world)
    {
        int count=0;
        if(j-1>=0 && i-1>=0 && world[i-1][j-1]==1)
        {
            count++;
        }

        if(j+1<=WORLD_WIDTH-1 && i+1<=WORLD_HEIGHT-1 && world[i+1][j+1]==1)
        {
            count++;
        }

        if(j+1<=WORLD_WIDTH-1 && i-1>=0 && world[i-1][j+1]==1)
        {
            count++;
        }

        if(i-1>=0 && world[i-1][j]==1)
        {
            count++;
        }

        if(i+1<=WORLD_HEIGHT-1 && world[i+1][j]==1)
        {
            count++;
        }

        if(j-1>=0 && i+1<=WORLD_HEIGHT-1 && world[i+1][j-1]==1)
        {
            count++;
        }

        if(j-1>=0 && world[i][j-1]==1)
        {
            count++;
        }

        if(j+1<=WORLD_WIDTH-1 && world[i][j+1]==1)
        {
            count++;
        }

        return count;
    }

    void gameOfLife(vector<vector<int>>& world)
    {
        vector<vector<int>> next(world.size(), vector<int>(world.at(0).size()));

        int WORLD_HEIGHT=world.size();
        int WORLD_WIDTH=world.at(0).size();

        for(int i=0; i<WORLD_HEIGHT; i++)
        {
            for(int j=0; j<WORLD_WIDTH; j++)
            {
                int alive=getNeighbourAliveCount(i, j, WORLD_HEIGHT, WORLD_WIDTH, world);
                if(world[i][j]==0)
                {
                    if(alive==3)
                    {
                        next[i][j]=1;
                    }
                }
                else
                {
                    if(alive<2)
                    {
                        next[i][j]=0;
                    }
                    else if(alive==2 || alive==3)
                    {
                        next[i][j]=1;
                    }
                    else
                    {
                        next[i][j]=0;
                    }
                }

            }
        }

        for(int i=0; i<WORLD_HEIGHT; i++)
        {
            for(int j=0; j<WORLD_WIDTH; j++)
            {
                world[i][j]=next[i][j];
            }
        }
    }
};
