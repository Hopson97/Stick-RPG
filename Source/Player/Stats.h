#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

struct Stats
{
    int intelligence;
    int charm;

    void reset()
    {
        intelligence = 0;
        charm = 0;
    }
};

#endif // STATS_H_INCLUDED
