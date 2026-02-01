# Modern C++ for High Performance Web Applications

C++ is a popular systems programming language. While it is not usually considered for web application development, Modern C++ (C++17/20/23) has a compelling set of features and libraries that make it suitable for demanding web workloads.

## Why Choose C++ for Web Applications?

- **Predictable Performance:** C++ provides deterministic memory management without a garbage collector, resulting in consistent latency and throughput.
- **Speed:** Native compilation and low-level optimizations allow C++ applications to outperform many managed language counterparts.
- **Resource Efficiency:** Fine-grained control over memory and CPU usage enables efficient scaling, especially in resource-constrained environments or cloud deployments. Topping the chart in cold start, memory usage in AWS Lambda ([See Lambda Performance Benchmarks](https://maxday.github.io/lambda-perf/)).
- **Low Latency:** Minimal runtime overhead means responses can be extremely fast, making C++ ideal for latency-sensitive APIs and real-time systems.
- **Access to Powerful Libraries:** Leverage a vast ecosystem of high-performance libraries for networking, memory management, task flows, data structures, cryptography, serialization, and more.
- **Hardware Utilization:** Modern C++ supports SIMD, AVX, and other hardware features, allowing you to maximize performance on specific server architectures (e.g., [Highway](https://github.com/google/highway)).
- **Performance-Aware Programming:** C++ encourages understanding and optimizing for performance at every level.
- **Direct Code Reuse:** Use robust, mature libraries directly, often without the need for wrappers or bindings.

C++ is well-known for powering databases, browsers, game engines, and system components. Today, you can use it to build everything from raw TCP servers to full-featured REST APIs and microservices, choosing your preferred level of abstraction.

## Common Concerns

- **Safety:** Risks of memory corruption, undefined behavior, and crashes are higher compared to managed languages.
- **Security:** Vulnerabilities such as buffer overflows and exploits require careful mitigation.
- **Complexity:** The language has a steep learning curve and requires disciplined engineering practices. It is harder to get right.

**Mitigation Strategies:**

- Adopt modern C++ best practices (RAII, smart pointers, static analysis).
- Validate all input data rigorously.
- Design services to be restartable and resilient.
- Use sanitizers, memory sentries and fuzzing tools during development.

## Notable C++ Web Frameworks and Libraries

| Framework          | Speed | Features             | Production Ready (2025)  |
| ------------------ | ----- | -------------------- | ------------------------ |
| Drogon             | 🚀🚀🚀   | ⭐⭐⭐                  | ✅                        |
| Lithium            | 🚀🚀🚀   | ⭐⭐½  (no WebSocket?) | ✅ (Windows build issues) |
| Oatpp              | 🚀🚀    | ⭐⭐⭐                  | ✅                        |
| CrowCpp            | 🚀🚀    | ⭐⭐⭐                  | ✅                        |
| userver            | 🚀🚀    | ⭐⭐⭐                  | ✅                        |
| mongoose           | 🚀🚀🚀   | ⭐⭐⭐                  | ✅ (great for embedded)   |
| ffread             | 🚀🚀🚀   | ⭐⭐⭐                  | ✅                        |
| glaze (networking) | ?     | ⭐⭐⭐                  |  ?                      |
| vixcpp             | 🚀🚀    | ⭐⭐⭐                 | ?                        |

**Popular Choices:**

- [Drogon](https://github.com/drogonframework/drogon): High-performance, full-featured.
- [Lithium](https://github.com/matt-42/lithium): High-performance, easy to use. Linux for now.
- [Oatpp](https://github.com/oatpp/oatpp): Modern, easy-to-use, and well-documented.
- [CrowCpp](https://github.com/CrowCpp/Crow): Inspired by Python Flask.
- [userver](https://github.com/userver-framework/userver): Coroutine-based, feature-rich.
- [mongoose](https://github.com/cesanta/mongoose): Lightweight, embeddable.
- [ffead-cpp](https://github.com/sumeetchhetri/ffead-cpp): High performance, extensive features.
- [glaze](https://github.com/stephenberry/glaze): Modern serialization and networking.
- [Metaspex](https://www.metaspex.com/): Enterprise-ready backend development platform.
- [vixcpp](https://github.com/vixcpp/vix): P2P and high-performance applications. Local-first execution, Asio-powered async I/O, modular architecture..

See [TechEmpower benchmarks](https://www.techempower.com/benchmarks/) for performance comparisons.

## Choosing Libraries: What to Consider

- **Community & Adoption:** Popular, well-maintained libraries are safer bets.
- **Performance:** Benchmarks and real-world usage. Always benchmark for your use case.
- **Security:** Active patching and secure defaults.
- **Features:** Does it support your use case (REST, WebSockets, GraphQL, etc.)?
- **Ease of Use:** Good documentation and examples.
- **C++ Standard Support:** Prefer libraries using modern C++ idioms(can help with safety, low level APIs may be more performant though, mix and benchmark).
- **License:** Ensure compatibility with your project.

## Package Management

- [vcpkg](https://vcpkg.io/)
- [conan](https://conan.io/)
- CMake's `FetchContent` - see [this](https://cliutils.gitlab.io/modern-cmake/README.html#) guide
- Git submodules
- Direct copy in repo - Good for extremely stable headers and utilities. Popularly used with single-header libraries.

**Tip:** Lock dependencies to specific versions or commits to avoid supply chain risks. Test thoroughly when upgrading.

## Build Methods (System?)

- [`CMake`](https://cliutils.gitlab.io/modern-cmake/README.html#) - Most widely used.
- Meson
- [`Bazel`](https://github.com/bazelbuild/bazel)
- GN - Popular in Google projects.
- Makefiles
- autotools - i.e. Autoconf to create a configure script, Automake to generate Makefile files, and Libtool to assist in building portable libraries. Consumers use Autotools to compile software by running the configure script and then the make command.

## Common Libraries for Web Services

- **JSON:** [nlohmann/json](https://github.com/nlohmann/json), [RapidJSON](https://github.com/Tencent/rapidjson), [Glaze](https://github.com/stephenberry/glaze)
- **Cryptography:** [argon2](https://github.com/P-H-C/phc-winner-argon2), [libsodium](https://github.com/jedisct1/libsodium), [jwt-cpp](https://github.com/Thalhammer/jwt-cpp)
- **Networking:** [Boost.Asio](https://www.boost.org/doc/libs/release/doc/html/boost_asio.html), [ZeroMQ](https://zeromq.org/)
- **Database Drivers and ORMs:** [libpqxx](https://github.com/jtv/libpqxx) (Postgres), [mongo-cxx-driver](https://github.com/mongodb/mongo-cxx-driver) or the driver embedded in your web framework. [TinyORM](https://github.com/silverqx/TinyORM).
- **Validation:** Validation can be handled through custom parsers, so you can use parser combinator libraries like [Boost.Spirit.X3](https://www.boost.org/doc/libs/release/libs/spirit/doc/x3/html/index.html) now replaced by [Boost.parser](https://www.boost.org/doc/libs/1_89_0/doc/html/parser.html) and [Lexy](https://github.com/foonathan/lexy).
- **Utilities and Standard Library:** [Boost](https://www.boost.org/), [unordered_dense](https://github.com/martinus/unordered_dense), [Folly](https://github.com/facebook/folly), [Poco](https://pocoproject.org/), [Abseil](https://abseil.io/docs/cpp/quickstart), [EASTL](https://abseil.io/docs/cpp/quickstart)
- **Messaging Queues and In-memory storage** [redis-plus-plus](https://github.com/sewenew/redis-plus-plus), [hiredis](https://github.com/redis/hiredis). These Redis compatible APIs alow you to use most popular in-memory stores like Pogocache, DragonFly and Valkey.  [rabbitmq-c](https://github.com/alanxz/rabbitmq-c), [AMQP](https://github.com/CopernicaMarketingSoftware/AMQP-CPP), [cppkafka](https://github.com/mfontanini/cppkafka), [librdkafka](https://github.com/confluentinc/librdkafka), [modern-cpp-kafka](https://github.com/morganstanley/modern-cpp-kafka)
- ML, Math, Matrices - [Eigen](http://eigen.tuxfamily.org/), [mlpack](https://github.com/mlpack/mlpack), [armadillo](https://vcpkg.io/en/package/armadillo)
- Identifiers - [boost-uuid](https://www.boost.org/libs/uuid)
- Vector search - [usearch](https://github.com/unum-cloud/usearch)

## Key Concepts

- **Authentication & Cryptography:** JWT, hashing, signing.
- **Validation:** Input validation, email/phone number parsing (see RFC-5322 for email).
- **Sockets & IPC:** ZeroMQ, Cap’n Proto, gRPC.
- **Messaging Queues:** Kafka, RabbitMQ.
- **Cloud SDKs:** AWS, Azure, GCP ([Google Cloud C++](https://github.com/googleapis/google-cloud-cpp), [AWS C++ SDK](https://github.com/aws/aws-sdk-cpp), [AWS Lambda C++ Runtime](https://github.com/awslabs/aws-lambda-cpp-runtime), [Azure C++ SDK](https://azure.github.io/azure-sdk-for-cpp/)).
- **Database Clients:** MongoDB, Postgres, Cassandra, CouchDB, ScyllaDB
- **Data Structures:** High-performance hashmaps, sets - ankerl's unordered_dense.h. See these: [ankerl's hashmap benchmark](https://martin.ankerl.com/2022/08/27/hashmap-bench-01/), [tessil's](https://tessil.github.io/2016/08/29/benchmark-hopscotch-map.html), [attractivechaos's](https://attractivechaos.wordpress.com/2018/01/13/revisiting-hash-table-performance/), [jacksonallan's](https://jacksonallan.github.io/c_cpp_hash_tables_benchmark/)
- **GraphQL:** Emerging support in some frameworks.
- **DevOps:** [Modern C++ DevOps](https://moderncppdevops.com/)

## Good Practices

- Use modern C++ features (smart pointers, `std::optional`, `std::expected`).
- Reserve exceptions for truly exceptional cases.
- Prefer prepared statements or constant strings for database queries to avoid SQL injection.
- Write comprehensive tests and use sanitizers (ASan, UBSan).
- Monitor for deadlocks, especially when using coroutines or async code.
- Study the documentation and source code of dependencies. The source code is the single source of truth. Documentation can be outdated. AI can be outdated or just wrong.
- When confused, benchmark, monitor for performance regressions, profile hot paths, benchmark different approaches: Google Benchmark is a nice microbenchmarking lib. [Compiler explorer](https://godbolt.org/) is a good tool to quickly test patterns and compare compiler output. Other useful tools are [Quickbench](https://quick-bench.com/) (Quick microbenchmarking), [Cpp Insights](https://cppinsights.io/) (See your source code with the eyes of a compiler).
- Spend time to setup your dev environment, LSPs, debuggers are really useful. Lots of time is spent debugging.

## Strategies for Using C++ in Web Backends

### 1. C++ for Latency-Critical Microservices

Use C++ to implement microservices that are performance bottlenecks or require deterministic latency—such as authentication, inferencing, video/image processing, real-time analytics, search engines, recommendation engines, or protocol gateways. These services benefit from C++’s predictable memory management, extensive library support,direct hardware access, and minimal runtime overhead.

- **Example:** Meta (Facebook) uses C++ (and C) for core messaging and real-time infrastructure.
- **Integration:** Expose C++ services via REST/gRPC, and orchestrate them with higher-level languages (Go, Node.js, Python) or a more general C++ service for non-critical paths.
- **Benefits:** Achieve sub-millisecond response times, reduce cloud costs, and maximize hardware utilization.

### 2. Full-Stack C++ Web Applications

Build entire web applications or APIs in C++ using modern frameworks (Drogon, Oatpp, userver). This approach is ideal for teams with strong C++ expertise or applications where performance, efficiency, and control are paramount.

- **Advantages:**
  - End-to-end type safety and performance.
  - Unified toolchain and deployment.
  - Fine-grained control over threading, memory, and networking.
- **Use Cases:** Financial trading platforms, IoT backends, embedded web servers, SaaS with strict SLAs.

### 3. Hybrid Approach: C++ with Scripting/Managed Languages

Combine C++ for core logic with scripting or managed languages for flexibility and rapid development.

- **Pattern:** Core libraries, performance-sensitive modules, or plugins in C++; business logic, orchestration, and UI in Python, C# and JS (with HTML and CSS).
- **Interoperability:** Use FFI (Foreign Function Interface), REST/gRPC, or WebAssembly to bridge languages.
- **Example:** Use C++ for a high-throughput data processing engine, and expose it to a Go, C# or Node.js Express API.

### 4. C++ for Edge and Serverless

Deploy C++ in serverless (AWS Lambda, Azure Functions) or edge environments where cold start time, memory footprint, and execution speed are critical.

- **Benefits:** C++ consistently tops benchmarks for cold start and memory usage ([see Lambda Performance Benchmarks](https://maxday.github.io/lambda-perf/)).
- **Use Cases:** Real-time APIs, IoT gateways, CDN edge logic.

### 5. C++ for Specialized Backend Components

Leverage C++ for components like:

- **Custom protocol servers** (e.g., WebSocket, MQTT, custom TCP/UDP).
- **High-performance caches** and in-memory stores.
- **Data serialization/deserialization** (e.g., JSON, zpp::bits, Protobuf, Cap’n Proto).
- **Cryptography and security modules**.
- **Media Servers**

## Summary

C++ is not just for systems programming—it is a first-class choice for high-performance web backends. Whether you use it for critical microservices, full-stack APIs, or specialized components, C++ delivers unmatched speed, efficiency, and control for demanding web workloads.

## Further Reading & Research

- [AWS Lambda Concurrency](https://www.nordhero.com/posts/aws-lambda-concurrency/)
- [Concurrency Evaluation in C++](https://github.com/villekr/concurrency-eval-cpp)
- [C++ with AWS Lambda Custom Runtime](https://tutorialsdojo.com/exploring-c-with-aws-lambda-custom-runtime/)
- [Learn CMake](https://cliutils.gitlab.io/modern-cmake/README.html#)
- [awesome-cpp](https://github.com/fffaraz/awesome-cpp)
- [Reddit discussion on useful tools](https://www.reddit.com/r/cpp/comments/103tli7/what_are_the_musthave_tools_for_any_c_developer/)

Modern C++ empowers you to build web applications and services that are fast, efficient, and robust—provided you follow best practices and leverage the right tools.

----------------------------

## Examples and Demo's

![image](./images/backend-arch.png)

[Drogon C++ backend for simple marketplace app. Demos Auth, PubSub and Websockets.](https://github.com/uzoochogu/buyer-backend)

[Drogon + HTMX](https://github.com/brakmic/HDA_with_Cpp)

[Drogon used in a Discord Bot by Ruslan](https://github.com/ruslan-ilesik/games_bot)

## Video Presentation link

[![Video Thumbnail](https://img.youtube.com/vi/7ddZQAYWIn0/0.jpg)](https://youtu.be/7ddZQAYWIn0)


## Presentation Document

[`cpp for high performance web apps`](./cpp%20for%20high%20performance%20web%20apps.pdf)
