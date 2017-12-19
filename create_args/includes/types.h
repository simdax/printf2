
#ifndef __TYPES_H
# define __TYPES_H

# define ABS(value)	value < 0 ? -value : value
# define IF(value)	value < 0 ? 0 : value

typedef struct		s_num
{
  int    		sign;
  int    		alternate; // 0 1
  int			space;
  int    		base;	
  char			type;
  char			*modifiers;
  int			padding; // neg means right
  char			zero; // neg means right
  int	       		left;
  int    		precision; // neg means right
  char			*value;
  int    		str_len; // size of number rep
  size_t		count; // nb of printed letters
}			t_num;

typedef struct 		s_str
{
  int				padding;
  void			*value;
}					t_str;

#endif
