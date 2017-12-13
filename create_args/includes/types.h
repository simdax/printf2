
#ifndef __TYPES_H
# define __TYPES_H

# define ABS(value)	value < 0 ? -value : value
# define IF(value)	value < 0 ? 0 : value

typedef struct		s_num
{
  int			sign; // -1 0 1
  int			alternate; // 0 1
  //	void			(*print)(struct s_num*);
  char			type;
  int			padding; // neg means right
  char			type_padding; // neg means right
  int			left;
  int			precision; // neg means right
  char			*value;
  int			str_len; // size of number rep
  size_t		count; // nb of printed letters
}			t_num;

typedef struct 		s_str
{
  int				padding;
  void			*value;
}					t_str;

#endif
