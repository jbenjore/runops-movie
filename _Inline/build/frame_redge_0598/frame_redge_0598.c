/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.19_01 from the
 * contents of frame_redge_0598.xs. Do not edit this file, edit frame_redge_0598.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "frame_redge_0598.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "INLINE.h"
#line 34
#include <Judy.h>
void*
read_edge_as_redge(PerlIO *fh) {
    SV *line_sv;
    char *line;
    Pvoid_t redge = 0;
    Pvoid_t *pxedge;
    STRLEN line_len;
    int Rc_int, x, y;

    line_sv = newSVpv("",0);
    while (sv_gets(line_sv,fh,0)) {
        line = SvPV(line_sv,line_len);
        if ( 2 != sscanf(line,"edge(%x,%x).",&x,&y) ) {
            croak(line);
        }

        JLI(pxedge,redge,y);
        J1S(Rc_int,*pxedge,x);
    }
    SvREFCNT_dec(line_sv);

    return redge;
}

void
write_redge( void *redge, PerlIO *ofh ) {
    PWord_t pxedge;
    Word_t x, y;
    int found_x;

    pxedge = y = 0;
    JLF(pxedge,redge,y);
    while ( pxedge ) {
       found_x = x = 0;
       J1F(found_x,(Pvoid_t)*pxedge,x);
       while (found_x) {
           PerlIO_printf(ofh,"redge(%x,%x).\n",x,y);

           J1N(found_x,(Pvoid_t)*pxedge,x);
       }

       JLN(pxedge,redge,y);
    }
}

void
free_redge(void *redge) {
    PWord_t pxedge;
    Word_t y;
    int freed;

    y = 0;
    JLF(pxedge,redge,y);
    while (pxedge) {
        J1FA(freed,(Pvoid_t)*pxedge);
        JLN(pxedge,redge,y);
    }
    JLFA(freed,redge);
}


#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#line 82 "frame_redge_0598.c"

XS(XS_main_read_edge_as_redge); /* prototype to pass -Wmissing-prototypes */
XS(XS_main_read_edge_as_redge)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       Perl_croak(aTHX_ "Usage: %s(%s)", "main::read_edge_as_redge", "fh");
    PERL_UNUSED_VAR(cv); /* -W */
    {
	PerlIO *	fh = IoIFP(sv_2io(ST(0)));
	void *	RETVAL;
	dXSTARG;

	RETVAL = read_edge_as_redge(fh);
	XSprePUSH; PUSHi(PTR2IV(RETVAL));
    }
    XSRETURN(1);
}


XS(XS_main_write_redge); /* prototype to pass -Wmissing-prototypes */
XS(XS_main_write_redge)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       Perl_croak(aTHX_ "Usage: %s(%s)", "main::write_redge", "redge, ofh");
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	void *	redge = INT2PTR(void *,SvIV(ST(0)));
	PerlIO *	ofh = IoIFP(sv_2io(ST(1)));
#line 82 "frame_redge_0598.xs"
	I32* temp;
#line 125 "frame_redge_0598.c"
#line 84 "frame_redge_0598.xs"
	temp = PL_markstack_ptr++;
	write_redge(redge, ofh);
	if (PL_markstack_ptr != temp) {
          /* truly void, because dXSARGS not invoked */
	  PL_markstack_ptr = temp;
	  XSRETURN_EMPTY; /* return empty stack */
        }
        /* must have used dXSARGS; list context implied */
	return; /* assume stack size is correct */
#line 136 "frame_redge_0598.c"
	PUTBACK;
	return;
    }
}


XS(XS_main_free_redge); /* prototype to pass -Wmissing-prototypes */
XS(XS_main_free_redge)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       Perl_croak(aTHX_ "Usage: %s(%s)", "main::free_redge", "redge");
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	void *	redge = INT2PTR(void *,SvIV(ST(0)));
#line 98 "frame_redge_0598.xs"
	I32* temp;
#line 160 "frame_redge_0598.c"
#line 100 "frame_redge_0598.xs"
	temp = PL_markstack_ptr++;
	free_redge(redge);
	if (PL_markstack_ptr != temp) {
          /* truly void, because dXSARGS not invoked */
	  PL_markstack_ptr = temp;
	  XSRETURN_EMPTY; /* return empty stack */
        }
        /* must have used dXSARGS; list context implied */
	return; /* assume stack size is correct */
#line 171 "frame_redge_0598.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_frame_redge_0598); /* prototype to pass -Wmissing-prototypes */
XS(boot_frame_redge_0598)
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

        newXS("main::read_edge_as_redge", XS_main_read_edge_as_redge, file);
        newXS("main::write_redge", XS_main_write_redge, file);
        newXS("main::free_redge", XS_main_free_redge, file);
    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

