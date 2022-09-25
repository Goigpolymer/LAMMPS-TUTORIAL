#!/bin/bash

mpirun -n 2 lmp_mpi -in in.table
#mkdir Run
#cp dump.hex.* Run

