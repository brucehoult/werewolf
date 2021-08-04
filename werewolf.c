#include <stddef.h>

#define GD_HAVE_LONG_LONG
#include "runtime.h"

extern descriptor_t dylanZtrue;	/* #t */

#define obj_True dylanZtrue.heapptr
extern descriptor_t dylanZfalse;	/* #f */

#define obj_False dylanZfalse.heapptr

#define GENERAL_ENTRY(func) \
    ((entry_t)SLOT(func, void *, 8))
#define GENERIC_ENTRY(func) \
    ((entry_t)SLOT(func, void *, 32))

#define GD_CTASSERT(name, x) \
    typedef char gd_assert_ ## name[(x) ? 1 : -1];
#define GD_VERIFY_SIZE_ASSUMPTION(name, type, size)\
    GD_CTASSERT(size_ ## name, sizeof(type) == (size))
#define GD_VERIFY_ALIGN_ASSUMPTION(name, type, align)\
    typedef struct { char c; type x; } \
      gd_align_ ## name; \
    GD_CTASSERT(align_ ## name, offsetof(gd_align_ ## name, x) == (align))

GD_VERIFY_SIZE_ASSUMPTION(general, descriptor_t, 8);
GD_VERIFY_ALIGN_ASSUMPTION(general, descriptor_t, 4);
GD_VERIFY_SIZE_ASSUMPTION(heap, heapptr_t, 4);
GD_VERIFY_ALIGN_ASSUMPTION(heap, heapptr_t, 4);
GD_VERIFY_SIZE_ASSUMPTION(boolean, int, 4);
GD_VERIFY_ALIGN_ASSUMPTION(boolean, int, 4);
GD_VERIFY_SIZE_ASSUMPTION(long_long, long long, 8);
GD_VERIFY_ALIGN_ASSUMPTION(long_long, long long, 4);
GD_VERIFY_SIZE_ASSUMPTION(long, long, 4);
GD_VERIFY_ALIGN_ASSUMPTION(long, long, 4);
GD_VERIFY_SIZE_ASSUMPTION(int, int, 4);
GD_VERIFY_ALIGN_ASSUMPTION(int, int, 4);
GD_VERIFY_SIZE_ASSUMPTION(uint, unsigned int, 4);
GD_VERIFY_ALIGN_ASSUMPTION(uint, unsigned int, 4);
GD_VERIFY_SIZE_ASSUMPTION(short, short, 2);
GD_VERIFY_ALIGN_ASSUMPTION(short, short, 2);
GD_VERIFY_SIZE_ASSUMPTION(ushort, unsigned short, 2);
GD_VERIFY_ALIGN_ASSUMPTION(ushort, unsigned short, 2);
GD_VERIFY_SIZE_ASSUMPTION(float, float, 4);
GD_VERIFY_ALIGN_ASSUMPTION(float, float, 4);
GD_VERIFY_SIZE_ASSUMPTION(double, double, 8);
GD_VERIFY_ALIGN_ASSUMPTION(double, double, 4);
GD_VERIFY_SIZE_ASSUMPTION(long_double, long double, 16);
GD_VERIFY_ALIGN_ASSUMPTION(long_double, long double, 16);
GD_VERIFY_SIZE_ASSUMPTION(ptr, void *, 4);
GD_VERIFY_ALIGN_ASSUMPTION(ptr, void *, 4);

/* Define Constant <activity> */

/* <activity> allocated as werewolfZwerewolfZCLS_activity */


/* Define Constant <num-people> */

/* <num-people> is <integer> */


/* Define Constant <probability> */

/* <probability> is <double-float> */


/* Define Constant <fp> */

/* <fp> is <double-float> */


/* Define Constant win-probability */

/* win-probability allocated as werewolfZwerewolfZwin_probability */

extern descriptor_t standard_ioZstandard_ioZVstandard_outputV;	/* *standard-output* */

#include <stdlib.h>

extern heapptr_t dylanZdylan_visceraZCLS_simple_object_vector_MAKER_FUN(descriptor_t *orig_sp, long A0, descriptor_t A1);	/* maker for <simple-object-vector> */

extern descriptor_t werewolfZliteral;	/* proxy for <integer> */

extern void formatZformatZformat_METH(descriptor_t *orig_sp, heapptr_t A0, heapptr_t A1, heapptr_t A2, heapptr_t A3);	/* format{<buffered-stream>, <byte-string>} */

extern struct heapobj werewolfZstr_ROOT;

extern struct heapobj werewolfZliteral_ROOT;

extern struct heapobj SYM_werewolves_kill_HEAP;

extern struct heapobj SYM_villagers_lynch_HEAP;

extern struct heapobj SYM_seer_asks_HEAP;

/* win-probability */
double werewolfZwerewolfZwin_probability_FUN(descriptor_t *orig_sp, heapptr_t A_activity /* activity */, long A_werewolves /* werewolves */, long A_villagers /* villagers */, int A_seer_livesQUERY /* seer-lives? */, long A_villagers_confirmed /* villagers-confirmed */, long A_wolves_confirmed /* wolves-confirmed */)
{
    descriptor_t *cluster_0_top;
    heapptr_t L_activity; /* activity */
    long L_werewolves; /* werewolves */
    long L_villagers; /* villagers */
    int L_seer_livesQUERY; /* seer-lives? */
    long L_villagers_confirmed; /* villagers-confirmed */
    long L_wolves_confirmed; /* wolves-confirmed */
    descriptor_t L_temp;
    heapptr_t L_temp_2; /* temp */
    heapptr_t L_instance; /* instance */
    descriptor_t L_temp_3;
    descriptor_t L_temp_4;
    descriptor_t L_temp_5;
    descriptor_t L_temp_6;
    descriptor_t L_temp_7;
    descriptor_t L_temp_8;
    double L_prob; /* prob */
    double L_b; /* b */
    double L_res; /* res */
    double L_res_2; /* res */
    long L_arg5; /* arg5 */
    double L_arg1; /* arg1 */
    double L_arg1_2; /* arg1 */
    double L_arg1_3; /* arg1 */
    double L_total_unknown; /* total-unknown */
    double L_arg1_4; /* arg1 */
    double L_arg1_5; /* arg1 */
    double L_total_people; /* total-people */
    double L_res_3; /* res */
    double L_res_4; /* res */
    double L_prob_seer_killed; /* prob-seer-killed */
    double L_prob_seer_killed_2; /* prob-seer-killed */
    long L_arg3; /* arg3 */
    double L_arg1_6; /* arg1 */
    double L_arg1_7; /* arg1 */
    long L_arg5_2; /* arg5 */
    double L_arg1_8; /* arg1 */
    double L_arg1_9; /* arg1 */
    double L_arg1_10; /* arg1 */


    /* #line 186 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
    while (1) {
	L_activity = A_activity;
	L_werewolves = A_werewolves;
	L_villagers = A_villagers;
	L_seer_livesQUERY = A_seer_livesQUERY;
	L_villagers_confirmed = A_villagers_confirmed;
	L_wolves_confirmed = A_wolves_confirmed;

	/* #line 66 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	if ((L_temp = standard_ioZstandard_ioZVstandard_outputV).heapptr == NULL) abort();
	L_temp_2 = L_temp.heapptr;
	/* maker for <simple-object-vector> */
	L_instance = dylanZdylan_visceraZCLS_simple_object_vector_MAKER_FUN(orig_sp, 6, dylanZfalse);
	L_temp_3.heapptr = L_activity;
	L_temp_3.dataword.l = 0;
	SLOT(L_instance, descriptor_t, 8 + 0 * sizeof(descriptor_t)) = L_temp_3;
	L_temp_4.heapptr = werewolfZliteral.heapptr;
	L_temp_4.dataword.l = L_werewolves;
	SLOT(L_instance, descriptor_t, 8 + 1 * sizeof(descriptor_t)) = L_temp_4;
	L_temp_5.heapptr = werewolfZliteral.heapptr;
	L_temp_5.dataword.l = L_villagers;
	SLOT(L_instance, descriptor_t, 8 + 2 * sizeof(descriptor_t)) = L_temp_5;
	L_temp_6.heapptr = (L_seer_livesQUERY ? obj_True : obj_False);
	L_temp_6.dataword.l = 0;
	SLOT(L_instance, descriptor_t, 8 + 3 * sizeof(descriptor_t)) = L_temp_6;
	L_temp_7.heapptr = werewolfZliteral.heapptr;
	L_temp_7.dataword.l = L_villagers_confirmed;
	SLOT(L_instance, descriptor_t, 8 + 4 * sizeof(descriptor_t)) = L_temp_7;
	L_temp_8.heapptr = werewolfZliteral.heapptr;
	L_temp_8.dataword.l = L_wolves_confirmed;
	SLOT(L_instance, descriptor_t, 8 + 5 * sizeof(descriptor_t)) = L_temp_8;
	/* format{<buffered-stream>, <byte-string>} */
	formatZformatZformat_METH(orig_sp, L_temp_2, &werewolfZstr_ROOT, &werewolfZliteral_ROOT, L_instance);

	/* #line 69 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	if ((L_werewolves == 0)) {

	    /* #line 69 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    L_prob = 0.1e1;
	}
	else 
	/* #line 70 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	if ((L_villagers < L_werewolves)) {

	    /* #line 70 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    L_prob = 0.0;
	}
	else /* #line {Class <compound-macro-source-location>} */
	if ((L_activity == &SYM_werewolves_kill_HEAP)) {
	    if (L_seer_livesQUERY) {

		/* #line 75 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_b = ((double)L_villagers);
		L_res = (0.1e1 / L_b);

		/* #line 76 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_res_2 = (((double)L_villagers_confirmed) / L_b);

		/* #line 77 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 81 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_arg5 = (L_villagers - 1);

		/* #line 81 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_villagers_lynch_HEAP, L_werewolves, L_arg5, FALSE, 0, 0);

		/* #line 87 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 88 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_2 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_villagers_lynch_HEAP, L_werewolves, L_arg5, TRUE, (L_villagers_confirmed - 1), L_wolves_confirmed);

		/* #line 88 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 95 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_3 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_villagers_lynch_HEAP, L_werewolves, L_arg5, TRUE, L_villagers_confirmed, L_wolves_confirmed);

		/* #line 95 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 95 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_prob = (((L_res * L_arg1) + (L_res_2 * L_arg1_2)) + (((0.1e1 - L_res) - L_res_2) * L_arg1_3));
	    }
	    else {

		/* #line 99 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		A_activity = &SYM_villagers_lynch_HEAP;
		A_werewolves = L_werewolves;
		A_villagers = (L_villagers - 1);
		A_seer_livesQUERY = FALSE;
		A_villagers_confirmed = 0;
		A_wolves_confirmed = 0;
		goto block0;
	    }
	}
	else {
	    /* #line {Class <unknown-source-location>} */
	    /* #line {Class <compound-macro-source-location>} */
	    if ((L_activity == &SYM_seer_asks_HEAP)) {
		if (L_seer_livesQUERY) {

		    /* #line 104 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 104 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 104 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 104 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 104 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    L_total_unknown = ((double)((((L_werewolves + L_villagers) - L_wolves_confirmed) - L_villagers_confirmed) - 1));

		    /* #line 105 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 105 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 106 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 106 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 112 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 113 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    /* win-probability */
		    L_arg1_4 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_werewolves_kill_HEAP, L_werewolves, L_villagers, TRUE, (L_villagers_confirmed + 1), L_wolves_confirmed);

		    /* #line 120 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		    /* #line 120 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    /* win-probability */
		    L_arg1_5 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_werewolves_kill_HEAP, L_werewolves, L_villagers, TRUE, L_villagers_confirmed, (L_wolves_confirmed + 1));

		    /* #line 120 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    L_prob = (((((double)(L_villagers - L_villagers_confirmed)) / L_total_unknown) * L_arg1_4) + ((((double)(L_werewolves - L_wolves_confirmed)) / L_total_unknown) * L_arg1_5));
		}
		else {

		    /* #line 124 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    A_activity = &SYM_werewolves_kill_HEAP;
		    A_werewolves = L_werewolves;
		    A_villagers = L_villagers;
		    A_seer_livesQUERY = FALSE;
		    A_villagers_confirmed = 0;
		    A_wolves_confirmed = 0;
		    goto block0;
		}
	    }
	    else 
	    /* #line 128 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    if ((L_werewolves == L_villagers)) {

		/* #line 129 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_prob = 0.0;
	    }
	    else 
	    /* #line 130 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    if ((L_wolves_confirmed == 2)) {

		/* #line 131 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_prob = 0.1e1;
	    }
	    else {

		/* #line 141 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 141 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_total_people = ((double)(L_werewolves + L_villagers));

		/* #line 143 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 145 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 145 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_res_3 = (((double)L_wolves_confirmed) / L_total_people);
		L_res_4 = (((double)(L_werewolves - L_wolves_confirmed)) / L_total_people);
		if (L_seer_livesQUERY) {

		    /* #line 146 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    L_prob_seer_killed = (0.1e1 / L_total_people);
		}
		else {

		    /* #line 146 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		    L_prob_seer_killed = 0.0;
		}

		/* #line 146 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_prob_seer_killed_2 = L_prob_seer_killed;

		/* #line 148 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 150 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 150 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 153 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_arg3 = (L_werewolves - 1);

		/* #line 157 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 157 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_6 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_seer_asks_HEAP, L_arg3, L_villagers, L_seer_livesQUERY, L_villagers_confirmed, (L_wolves_confirmed - 1));

		/* #line 164 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_7 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_seer_asks_HEAP, L_arg3, L_villagers, L_seer_livesQUERY, L_villagers_confirmed, L_wolves_confirmed);

		/* #line 164 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 168 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_arg5_2 = (L_villagers - 1);

		/* #line 168 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_8 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_seer_asks_HEAP, L_werewolves, L_arg5_2, FALSE, 0, 0);

		/* #line 168 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 174 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 175 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_9 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_seer_asks_HEAP, L_werewolves, L_arg5_2, L_seer_livesQUERY, (L_villagers_confirmed - 1), L_wolves_confirmed);

		/* #line 175 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 182 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		/* win-probability */
		L_arg1_10 = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_seer_asks_HEAP, L_werewolves, L_arg5_2, L_seer_livesQUERY, L_villagers_confirmed, L_wolves_confirmed);

		/* #line 182 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

		/* #line 182 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
		L_prob = (((((L_res_3 * L_arg1_6) + (L_res_4 * L_arg1_7)) + (L_prob_seer_killed_2 * L_arg1_8)) + ((((double)L_villagers_confirmed) / L_total_people) * L_arg1_9)) + (((((double)(L_villagers - L_villagers_confirmed)) / L_total_people) - L_prob_seer_killed_2) * L_arg1_10));
	    }
	}

	/* #line 185 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	return L_prob;
      block0:;
    }
}


/* Define Constant main */

/* main allocated as werewolfZwerewolfZmain */

extern struct heapobj werewolfZstr_ROOT_2;

extern void streamsZstreamsZforce_output_METH(descriptor_t *orig_sp, heapptr_t A0, heapptr_t A1);	/* force-output{<buffered-stream>} */

extern struct heapobj dylanZempty_list_ROOT;

extern void common_dylanZcommon_extensionsZexit_application_FUN(descriptor_t *orig_sp, long A0);	/* exit-application */

/* main */
descriptor_t * werewolfZwerewolfZmain_FUN(descriptor_t *orig_sp, descriptor_t A0, descriptor_t A1)
{
    descriptor_t *cluster_0_top;
    long L_i; /* i */
    long L_i_2; /* i */
    double L_prob; /* prob */
    descriptor_t L_temp;
    heapptr_t L_temp_2; /* temp */
    heapptr_t L_instance; /* instance */
    descriptor_t L_temp_3;
    descriptor_t L_temp_4;
    descriptor_t L_temp_5;
    heapptr_t L_temp_6; /* temp */


    /* #line 199 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
    /* #line {Class <compound-macro-source-location>} */
    L_i = 2;
    while (1) {
	L_i_2 = L_i;
	/* #line {Class <compound-macro-source-location>} */
	if ((100 < L_i_2)) {
	    goto block0;
	}
	else {

	    /* #line 195 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    /* win-probability */
	    L_prob = werewolfZwerewolfZwin_probability_FUN(orig_sp, &SYM_werewolves_kill_HEAP, 2, L_i_2, FALSE, 0, 0);

	    /* #line 196 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */

	    /* #line 196 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    if ((L_temp = standard_ioZstandard_ioZVstandard_outputV).heapptr == NULL) abort();
	    L_temp_2 = L_temp.heapptr;
	    /* maker for <simple-object-vector> */
	    L_instance = dylanZdylan_visceraZCLS_simple_object_vector_MAKER_FUN(orig_sp, 2, dylanZfalse);
	    L_temp_3.heapptr = werewolfZliteral.heapptr;
	    L_temp_3.dataword.l = ((L_i_2 + 2) + 1);
	    SLOT(L_instance, descriptor_t, 8 + 0 * sizeof(descriptor_t)) = L_temp_3;
	    L_temp_4.heapptr = make_double_float(L_prob);
	    L_temp_4.dataword.l = 0;
	    SLOT(L_instance, descriptor_t, 8 + 1 * sizeof(descriptor_t)) = L_temp_4;
	    /* format{<buffered-stream>, <byte-string>} */
	    formatZformatZformat_METH(orig_sp, L_temp_2, &werewolfZstr_ROOT_2, &werewolfZliteral_ROOT, L_instance);

	    /* #line 197 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    if ((L_temp_5 = standard_ioZstandard_ioZVstandard_outputV).heapptr == NULL) abort();
	    L_temp_6 = L_temp_5.heapptr;

	    /* #line 197 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
	    /* force-output{<buffered-stream>} */
	    streamsZstreamsZforce_output_METH(orig_sp, L_temp_6, &dylanZempty_list_ROOT);
	    /* #line {Class <compound-macro-source-location>} */
	    L_i = (L_i_2 + 1);
	}
    }
  block0:;

    /* #line 199 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
    /* exit-application */
    common_dylanZcommon_extensionsZexit_application_FUN(orig_sp, 0);
    return orig_sp + 0;
}


/* Top level form. */

extern heapptr_t common_dylanZcommon_extensionsZapplication_name_FUN(descriptor_t *orig_sp);	/* application-name */

extern heapptr_t common_dylanZcommon_extensionsZapplication_arguments_FUN(descriptor_t *orig_sp);	/* application-arguments */

/* form at "werewolf.dylan", line 202, characters 1 through 49:
    main(application-name(), application-arguments());
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   */
void werewolfZLINE_202(descriptor_t *orig_sp)
{
    heapptr_t L_arg0; /* arg0 */
    heapptr_t L_arg1; /* arg1 */
    descriptor_t L_temp;
    descriptor_t L_temp_2;

    /* #line {Class <unknown-source-location>} */

    /* #line 202 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
    /* application-name */
    L_arg0 = common_dylanZcommon_extensionsZapplication_name_FUN(orig_sp);

    /* #line 202 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
    /* application-arguments */
    L_arg1 = common_dylanZcommon_extensionsZapplication_arguments_FUN(orig_sp);

    /* #line 202 "/Users/bruce/programs/dylan/werewolf/werewolf.dylan" */
    L_temp.heapptr = L_arg0;
    L_temp.dataword.l = 0;
    L_temp_2.heapptr = L_arg1;
    L_temp_2.dataword.l = 0;
    /* main */
    werewolfZwerewolfZmain_FUN(orig_sp, L_temp, L_temp_2);
    return;
}

