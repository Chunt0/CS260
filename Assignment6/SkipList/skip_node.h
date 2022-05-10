/* Christopher Hunt
 * CS260
 * skip_node.h
 */
#ifndef SKIP_NODE_H
#define SKIP_NODE_H

#pragma once

struct SkipNode{
    int value;
    int height;
    int *length;
    SkipNode** next = nullptr;
};

#endif
