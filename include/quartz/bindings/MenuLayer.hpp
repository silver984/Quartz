namespace quartz {

struct MenuLayerBindings {
    MenuLayerBindings();
};

} // namespace quartz

// this variable's constructor queues bindings at static initialization time
// this ensures that bindings are populated before running scripts
static const quartz::MenuLayerBindings menuLayerBindings;