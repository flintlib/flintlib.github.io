/* Compile with

   gcc test_flint.c -lgmp -lflint

 */
#include <flint/fmpz.h>

int
main(int argc, char ** argv)
{
    fmpz_t af, bf, cf;

    if (argc != 3)
    {
        flint_printf("Example:  %s  3 5\n",
                     argv[0]);
        return 0;
    }

    /* Initialize */
    fmpz_init(af);
    fmpz_init(bf);
    fmpz_init(cf);

    /* Set factors */
    fmpz_set_str(af, argv[1], 10);
    fmpz_set_str(bf, argv[2], 10);

    /* Multiply */
    fmpz_mul(cf, af, bf);

    /* Print */
    flint_printf("a = %{fmpz}\n"
                 "b = %{fmpz}\n"
                 "a * b = %{fmpz}\n",
                 af, bf, cf);

    /* Clear */
    fmpz_clear(af);
    fmpz_clear(bf);
    fmpz_clear(cf);

    return 0;
}
