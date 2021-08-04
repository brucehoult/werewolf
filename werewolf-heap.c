#include "runtime.h"


/* <activity> */
extern struct dylanZdylan_visceraZCLS_union {
    heapptr_t PCTobject_class;	 /* %object-class */
    heapptr_t union_members;	 /* union-members */
    heapptr_t union_singletons;	 /* union-singletons */
} werewolf_L0;

descriptor_t werewolfZwerewolfZCLS_activity =
    { (heapptr_t) &werewolf_L0, { 0 } } /* roots[0] */;


/* win-probability */
extern struct dylanZdylan_visceraZCLS_method {
    heapptr_t PCTobject_class;	 /* %object-class */
    heapptr_t function_name;	 /* function-name */
    void * general_entry;	 /* general-entry */
    heapptr_t function_specializers;	 /* function-specializers */
    char function_restQUERY;	 /* function-rest? */
    char function_all_keysQUERY;	 /* function-all-keys? */
    unsigned char HOLE1[2];
    heapptr_t function_keywords;	 /* function-keywords */
    heapptr_t function_values;	 /* function-values */
    heapptr_t function_rest_value;	 /* function-rest-value */
    void * generic_entry;	 /* generic-entry */
} werewolf_L1;

descriptor_t werewolfZwerewolfZwin_probability =
{ (heapptr_t) &werewolf_L1, { 0 } } /* roots[1] */;


extern heapptr_t werewolf_L2;

descriptor_t werewolfZliteral =
{ (heapptr_t) &werewolf_L2, { 0 } } /* roots[2] */;


/* main */
extern struct dylanZdylan_visceraZCLS_method werewolf_L3;

descriptor_t werewolfZwerewolfZmain =
{ (heapptr_t) &werewolf_L3, { 0 } } /* roots[3] */;


/* heap base */

/* type-union(singleton(#"seer-asks"), singleton(#"werewolves-kill"), singleton(#"villagers-lynch")) */
extern struct dylanZdylan_visceraZCLS_class {
    heapptr_t PCTobject_class;	 /* %object-class */
    heapptr_t class_name;	 /* class-name */
    long unique_id;	 /* unique-id */
    heapptr_t direct_superclasses;	 /* direct-superclasses */
    heapptr_t all_superclasses;	 /* all-superclasses */
    heapptr_t closest_primary_superclass;	 /* closest-primary-superclass */
    heapptr_t direct_subclasses;	 /* direct-subclasses */
    char class_functionalQUERY;	 /* class-functional? */
    char class_primaryQUERY;	 /* class-primary? */
    char class_abstractQUERY;	 /* class-abstract? */
    char class_sealedQUERY;	 /* class-sealed? */
    heapptr_t class_deferred_evaluations;	 /* class-deferred-evaluations */
    heapptr_t class_key_defaulter;	 /* class-key-defaulter */
    heapptr_t class_maker;	 /* class-maker */
    heapptr_t class_new_slot_descriptors;	 /* class-new-slot-descriptors */
    heapptr_t class_slot_overrides;	 /* class-slot-overrides */
    heapptr_t class_all_slot_descriptors;	 /* class-all-slot-descriptors */
    long class_bucket;	 /* class-bucket */
    heapptr_t class_row;	 /* class-row */
} dylanZdylan_visceraZCLS_union_HEAP;

extern struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE0 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
} dylanZliteral_ROOT_4;

extern struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE3 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    descriptor_t PCTelement[3];	 /* %element */
} werewolf_L4;

struct dylanZdylan_visceraZCLS_union werewolf_L0 = {
(heapptr_t) &dylanZdylan_visceraZCLS_union_HEAP /* %object-class */,
    (heapptr_t) &dylanZliteral_ROOT_4 /* union-members */,
    (heapptr_t) &werewolf_L4 /* union-singletons */,
};

/* win-probability */
extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_method_HEAP;

extern const struct dylanZdylan_visceraZCLS_byte_string_SIZE15 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    unsigned char PCTelement[15];	 /* %element */
} werewolf_L5;

extern struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE6 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    descriptor_t PCTelement[6];	 /* %element */
} werewolf_L6;

extern struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE1 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    descriptor_t PCTelement[1];	 /* %element */
} werewolf_L7;

extern struct dylanZdylan_visceraZCLS_union dylanZliteral_ROOT_38;

struct dylanZdylan_visceraZCLS_method werewolf_L1 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_method_HEAP /* %object-class */,
    (heapptr_t) &werewolf_L5 /* function-name */,
    (void *) 0 /* general-entry */,
    (heapptr_t) &dylanZliteral_ROOT_4 /* function-specializers */,
    0 /* function-rest? */,
    0 /* function-all-keys? */,
    { 0, 0, }, /* hole */
    (heapptr_t) &werewolf_L6 /* function-keywords */,
    (heapptr_t) &werewolf_L7 /* function-values */,
    (heapptr_t) &dylanZliteral_ROOT_38 /* function-rest-value */,
    (void *) 0 /* generic-entry */,
};

/* proxy for <integer> */
extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_integer_HEAP;

heapptr_t werewolf_L2 =
    (heapptr_t) &dylanZdylan_visceraZCLS_integer_HEAP /* %object-class */;

/* main */
extern const struct dylanZdylan_visceraZCLS_byte_string_SIZE4 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    unsigned char PCTelement[4];	 /* %element */
} werewolf_L8;

extern struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE2 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    descriptor_t PCTelement[2];	 /* %element */
} werewolf_L9;

extern struct dylanZdylan_visceraZCLS_false {
    heapptr_t PCTobject_class;	 /* %object-class */
} dylan_L1;

extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_object_HEAP;

struct dylanZdylan_visceraZCLS_method werewolf_L3 = {
(heapptr_t) &dylanZdylan_visceraZCLS_method_HEAP /* %object-class */,
    (heapptr_t) &werewolf_L8 /* function-name */,
    (void *) 0 /* general-entry */,
    (heapptr_t) &werewolf_L9 /* function-specializers */,
    0 /* function-rest? */,
    0 /* function-all-keys? */,
    { 0, 0, }, /* hole */
    (heapptr_t) &dylan_L1 /* function-keywords */,
    (heapptr_t) &dylanZliteral_ROOT_4 /* function-values */,
    (heapptr_t) &dylanZdylan_visceraZCLS_object_HEAP /* function-rest-value */,
    (void *) 0 /* generic-entry */,
};

/* "%= w=%d, v=%d, seer=%=, sv=%d, sw=%d\n" */
extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_byte_string_HEAP;

const struct dylanZdylan_visceraZCLS_byte_string_SIZE37 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    unsigned char PCTelement[37];	 /* %element */
} werewolfZstr_ROOT = {
    (heapptr_t) &dylanZdylan_visceraZCLS_byte_string_HEAP /* %object-class */,
    37 /* size */,
    "%= w=%d, v=%d, seer=%=, sv=%d, sw=%d\n",
};

/* {a <pair>} */
extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_pair_HEAP;

extern struct dylanZdylan_visceraZCLS_method format_L118;

extern struct dylanZdylan_visceraZCLS_empty_list {
    heapptr_t PCTobject_class;	 /* %object-class */
    descriptor_t head;	 /* head */
    descriptor_t tail;	 /* tail */
} dylanZempty_list_ROOT;

struct dylanZdylan_visceraZCLS_pair {
    heapptr_t PCTobject_class;	 /* %object-class */
    descriptor_t head;	 /* head */
    descriptor_t tail;	 /* tail */
} werewolfZliteral_ROOT = {
    (heapptr_t) &dylanZdylan_visceraZCLS_pair_HEAP /* %object-class */,
    { (heapptr_t) &format_L118, { 0 } } /* head */,
    { (heapptr_t) &dylanZempty_list_ROOT, { 0 } } /* tail */,
};

/* "%d: %=\n" */
const struct dylanZdylan_visceraZCLS_byte_string_SIZE7 {
    heapptr_t PCTobject_class;	 /* %object-class */
    long size;	 /* size */
    unsigned char PCTelement[7];	 /* %element */
} werewolfZstr_ROOT_2 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_byte_string_HEAP /* %object-class */,
    7 /* size */,
    "%d: %=\n",
};

/* {a <simple-object-vector>} */
extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_simple_object_vector_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol {
    heapptr_t PCTobject_class;	 /* %object-class */
    descriptor_t symbol_string;	 /* symbol-string */
    long symbol_hashing;	 /* symbol-hashing */
    heapptr_t symbol_next;	 /* symbol-next */
} SYM_villagers_lynch_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_werewolves_kill_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_seer_asks_HEAP;

struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE3 werewolf_L4 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_simple_object_vector_HEAP /* %object-class */,
    3 /* size */,
    {
	{ (heapptr_t) &SYM_villagers_lynch_HEAP, { 0 } } /* %element[0] */,
	{ (heapptr_t) &SYM_werewolves_kill_HEAP, { 0 } } /* %element[1] */,
	{ (heapptr_t) &SYM_seer_asks_HEAP, { 0 } } /* %element[2] */,
    },
};

/* "win-probability" */
const struct dylanZdylan_visceraZCLS_byte_string_SIZE15 werewolf_L5 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_byte_string_HEAP /* %object-class */,
    15 /* size */,
    "win-probability",
};

/* {a <simple-object-vector>} */
extern struct dylanZdylan_visceraZCLS_symbol SYM_activity_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_werewolves_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_villagers_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_seer_livesQUERY_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_villagers_confirmed_HEAP;

extern struct dylanZdylan_visceraZCLS_symbol SYM_wolves_confirmed_HEAP;

struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE6 werewolf_L6 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_simple_object_vector_HEAP /* %object-class */,
    6 /* size */,
    {
	{ (heapptr_t) &SYM_activity_HEAP, { 0 } } /* %element[0] */,
	{ (heapptr_t) &SYM_werewolves_HEAP, { 0 } } /* %element[1] */,
	{ (heapptr_t) &SYM_villagers_HEAP, { 0 } } /* %element[2] */,
	{ (heapptr_t) &SYM_seer_livesQUERY_HEAP, { 0 } } /* %element[3] */,
	{ (heapptr_t) &SYM_villagers_confirmed_HEAP, { 0 } } /* %element[4] */,
	{ (heapptr_t) &SYM_wolves_confirmed_HEAP, { 0 } } /* %element[5] */,
    },
};

/* {a <simple-object-vector>} */
extern struct dylanZdylan_visceraZCLS_class dylanZdylan_visceraZCLS_double_float_HEAP;

struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE1 werewolf_L7 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_simple_object_vector_HEAP /* %object-class */,
    1 /* size */,
    {
	{ (heapptr_t) &dylanZdylan_visceraZCLS_double_float_HEAP, { 0 } } /* %element[0] */,
    },
};

/* "main" */
const struct dylanZdylan_visceraZCLS_byte_string_SIZE4 werewolf_L8 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_byte_string_HEAP /* %object-class */,
    4 /* size */,
    "main",
};

/* {a <simple-object-vector>} */
struct dylanZdylan_visceraZCLS_simple_object_vector_SIZE2 werewolf_L9 = {
    (heapptr_t) &dylanZdylan_visceraZCLS_simple_object_vector_HEAP /* %object-class */,
    2 /* size */,
    {
	{ (heapptr_t) &dylanZdylan_visceraZCLS_object_HEAP, { 0 } } /* %element[0] */,
	{ (heapptr_t) &dylanZdylan_visceraZCLS_object_HEAP, { 0 } } /* %element[1] */,
    },
};
