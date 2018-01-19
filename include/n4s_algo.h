#ifndef N4S_ALGO_H_
# define N4S_ALGO_H_

# define NB_GRADES (30)
# define NB_RADIUS (3)

# define POS (0)
# define GRADE (1)
# define CRITIC (600)
# define CRASHED (100)

# define SPEED_FORMULA ((1.0 - speed) / 3.0)

void		my_putfloat(int fd, float nbr);
int		is_end_of_track(float * info);

#endif /* !N4S_ALGO_H_ */
