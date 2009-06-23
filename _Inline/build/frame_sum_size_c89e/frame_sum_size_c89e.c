/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.19_01 from the
 * contents of frame_sum_size_c89e.xs. Do not edit this file, edit frame_sum_size_c89e.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "frame_sum_size_c89e.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "INLINE.h"
/* #line 109 */
#include <Judy.h>

int
_sum(Pvoid_t const vertex_size, Pvoid_t const edge, Word_t const x, Pvoid_t *sums) {
    PWord_t pyedge;
    PWord_t psum, psize;
    Word_t y, sum;
    int found_y;

    /* Already computed? */
    psum = 0;
    JLI( psum, *sums, x );
    if ( ! psum ) {
        croak("Can't allocate");
    }

    if ( *psum ) {
        return *psum;
    }
    else {
        /* size(X) + sum(size(children)) */
        psize = 0;
        JLG( psize, vertex_size, x );
        sum = psize ? *psize : 128;

        /* Fetch children */
        pyedge = 0;
        JLG( pyedge, edge, x );
        if ( ! pyedge ) {
            return *psum = sum;
        }

        /* Sum children */
        y = 0;
        J1F( found_y, (Pvoid_t)*pyedge, y );
        while ( found_y ) {
            sum += _sum( vertex_size, edge, y, sums );

            J1N( found_y, (Pvoid_t)*pyedge, y );
        }

        /* Refetch sum because *sums likely has changed */
        JLG(psum,*sums,x);
        return *psum = sum;
    }
}

void*
calc_sum( void* vertex_size, void* edge, int x ) {
    Pvoid_t *sums = malloc(sizeof(Pvoid_t));
    *sums = 0;
    _sum( vertex_size, edge, x, sums );
    return *sums;
}

#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#line 75 "frame_sum_size_c89e.c"

XS(XS_main_calc_sum); /* prototype to pass -Wmissing-prototypes */
XS(XS_main_calc_sum)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       Perl_croak(aTHX_ "Usage: %s(%s)", "main::calc_sum", "vertex_size, edge, x");
    PERL_UNUSED_VAR(cv); /* -W */
    {
	void *	vertex_size = INT2PTR(void *,SvIV(ST(0)));
	void *	edge = INT2PTR(void *,SvIV(ST(1)));
	int	x = (int)SvIV(ST(2));
	void *	RETVAL;
	dXSTARG;

	RETVAL = calc_sum(vertex_size, edge, x);
	XSprePUSH; PUSHi(PTR2IV(RETVAL));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_frame_sum_size_c89e); /* prototype to pass -Wmissing-prototypes */
XS(boot_frame_sum_size_c89e)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    char* file = __FILE__;

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXS("main::calc_sum", XS_main_calc_sum, file);
    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

