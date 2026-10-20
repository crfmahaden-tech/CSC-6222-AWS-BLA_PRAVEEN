# AWS Generative AI Optimization — Study Notes

## 1. Token Efficiency

Token efficiency concerns how effectively prompts and context use model input and output tokens. Review prompts for relevance and avoid unnecessary context while retaining information required for the task.

## 2. Model Selection and Cost

Choose a foundation model according to the application's requirements, quality expectations, latency needs, and cost constraints. Evaluate trade-offs rather than assuming one model is best for every use case.

## 3. Context and Inference Workloads

Context size and request patterns can affect inference behavior and resource use. Monitor workloads and evaluate configuration choices against the application's needs.

## 4. Intelligent Caching

Caching can reduce repeated work when a request or content can safely reuse a previous result. Cache design should account for freshness, correctness, security, and invalidation requirements.

## 5. Retrieval Performance

Retrieval methods, including semantic and vector search, can influence the relevance and speed of information supplied to an AI application. Evaluate retrieval quality as well as latency.

## 6. Reliability Patterns

Exponential backoff can help manage transient failures by spacing retries. Connection pooling can reduce repeated connection setup overhead. Apply these patterns with suitable retry limits and service-specific guidance.

## 7. Amazon Bedrock Optimization

Evaluate model choice, inference patterns, throughput requirements, and application performance in the context of the use case. Verify current service capabilities and configuration details in AWS documentation before implementation.

## 8. Cross-Region Inference

Cross-Region Inference can route inference requests across supported AWS Regions. Before using it, verify supported Regions and consider applicable data governance, privacy, residency, and organizational requirements.

## Study Reminder

These notes summarize concepts for learning purposes. Add course-specific details, official documentation links, and hands-on findings as they are verified.
