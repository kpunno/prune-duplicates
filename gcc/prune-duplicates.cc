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
#include "cgraph.h"

// Instantiate call graph
    // struct cgraph_node *node;

    // For each function
    // FOR_EACH_FUNCTION (node)
        // Declare vector of functions to be pruned

        // Get "default" version from cgraph_version_info
        // Get hash value of final adjustment
        // While (version_info.next)
            // Get hash value of final adjustment of this node
            // Compare to default hash value
            // IF (same)
                // Prune()

static unsigned int 
prune_duplicate_clones() 
{
    return 0;
}

namespace 
{

const pass_data pass_data_prune_duplicates =
{
    GIMPLE_PASS,        // type
    "prune_duplicates", // name
    OPTGROUP_NONE,      // optinfo _flags
    TV_NONE,            // tv_id
    0,                  // properties_required 
    0,                  // properties_provided
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

    unsigned int execute (function *) final override
    {
        return prune_duplicate_clones();
    }

}; // class pass_prune_duplicates

} // anon namespace

gimple_opt_pass *make_pass_prune_duplicates (gcc::context *ctxt)
{
    return new pass_prune_duplicates (ctxt);
}



