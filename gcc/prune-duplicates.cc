#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "rtl.h"
#include "tree.h"
#include "gimple.h"
#include "tree-pass.h"
#include "ssa.h"
#include "expmed.h"
#include "optabs-tree.h"
#include "tree-eh.h"
#include "gimple-iterator.h"
#include "gimplify-me.h"
#include "gimplify.h"
#include "tree-cfg.h"
#include "bitmap.h"
#include "tree-ssa-dce.h"
#include "memmodel.h"
#include "optabs.h"
#include "gimple-fold.h"
#include "internal-fn.h"


namespace 
{

const pass_data pass_data_prune_duplicates =
{
    GIMPLE_PASS,        // type
    "prune_duplicates", // name
    OPTGROUP_NONE,      // optinfo _flags
    TV_NONE,            // tv_id
    PROP_cfg,           // properties_required 
    PROP_gimple_lva,    // properties_provided
    0,                  // properties_destroyed
    0,                  // todo flags start
    0
};

class pass_prune_duplicates : public gimple_opt_pass 
{
public:
    pass_prune_duplicates (gcc::context *ctxt)
        : gimple_opt_pass (pass_data_prune_duplicates, ctxt)
    {}

    unsigned int execute (function *fun) final override;

}; // class pass_prune_duplicates

unsigned int
pass_prune_duplicates::execute(function *fun) 
{
    return 0;
}

}

gimple_opt_pass *make_pass_prune_duplicates (gcc::context *ctxt)
{
    return new pass_prune_duplicates (ctxt);
}



