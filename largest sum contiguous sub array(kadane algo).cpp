for(int i = 0; i < N; i++){

max_ending_here += Number[i];

        if(max_ending_here > max_so_far)max_so_far = max_ending_here;

        if(max_ending_here < 0)max_ending_here = 0;

    }