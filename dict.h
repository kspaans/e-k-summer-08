// The number of rows and columns in the field.
#define NCOLS 3
#define NROWS 3

// The global variable for the field of cells.
int **fld;

/******************************************************************************/

/* field_get(x, y)
 *
 * Does bounds checks while seeing if cell at (x,y) is
 * live or dead.
 * Returns 0 for dead cell
 * Returns 1 for live cell
 * Returns -1 for out-of-bounds indices
 */
int field_get(int x, int y);

/* kill(x, y)
 *
 * Checks (x, y) to see if a cell exists
 * if (x, y) exists, kill it and return 1
 * else return 0
 */
int killf(int x, int y);

/* spawn(x, y)
 *
 * Checks (x, y) to see if it's valid
 * if (x, y) exists or can be created, create it and return 1
 * else returns 0
 */
int spawn(int x, int y);

/* friends(x, y)
 *
 * Counts the number of valid friends
 * if friends exist return number
 * if none return 0
 * if invalid position return -1
 */
int friends(int x, int y);

/* field(x, y)
 *
 * Checks whether cell is alive or dead
 * if alive, return 1
 * if dead return 0
 */
int field(int x, int y);

/* rule(x, y, n)
 *
 * Kills or spawns cells at (x,y), give n many live neighbours
 * returns 0 on success.
 */
int rule(int x, int y, int n);

/* generator(n)
 *
 * Ages the field by n generations
 * Returns 0 on success.
 */
int generator(int n);
