#ifndef __TYPES_H
# define __TYPES_H

# define ABS(value)	value < 0 ? -value : value
# define IF(value)	value < 0 ? 0 : value

typedef struct		s_num
{
	int    		sign;
	int 		star;
	int    		alternate;
	int			space;
	int    		base;	
	char		type;
	char		*modifiers;
	int			padding;
	char		zero;
	int	    	left;
	int    		precision;
	char		*value;
	int    		str_len;
	size_t		count;
}					t_num;

typedef struct 		s_str
{
	int			padding;
	void		*value;
}					t_str;

#endif
