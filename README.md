# Project 5

CSCI-442 Spring 2016 Project 5 implemented by Jack Rosenthal. No unusal files
in my submission outside of what was given, nor interesting features. I
estimate I spent 3.5 hours on this project, most of which was spent figuring
out the given starter code and the rules of the game.

## Question 1

My `party_barrier` enforces two rules:

 1. 4 players must be in the party to begin playing a hole
 2. The party may not start the next hole until they have finished the current.

My `hole_signalling` condition enforces that only a single group may play the
hole at a time, using the help of a mutual exclusion. (See lines 87--92 in
`player.cpp`). The corresponding `notify_all` call allows the waiting golfer
to continue the condition check.

## Question 2

If two groups are waiting on a hole at the same time, at lines 87--92 a single
thread will be waiting on the hole. It is non-deterministic which thread will
be here, and thus, one group can pass another.
