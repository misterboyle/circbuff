//public method declarations
static double fetch(struct circbuff*);
static void push(struct circbuff*,double);

//private method declarations
static void moveTip(struct circbuff *);
static void moveTail(struct circbuff *);