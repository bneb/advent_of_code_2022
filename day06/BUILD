cc_library (
    name = "signal_processor",
    hdrs = ["signal_processor.h"],
)

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":signal_processor"
    ]
)

cc_test(
  name = "signal_processor_test",
  size = "small",
  srcs = ["signal_processor_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":signal_processor"
    ],
)
