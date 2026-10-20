# Architecture and Workflow Diagrams

## Overview

This file records diagrams that may support the Generative AI Optimization presentations. Add verified diagrams or links to the corresponding image files in this folder.

## Diagram 1: Token and Cost Optimization Workflow

Suggested flow:

1. Receive user request.
2. Prepare and optimize prompt/context.
3. Select an appropriate model for the use case.
4. Run inference.
5. Measure quality, latency, token usage, and cost.
6. Review results and iterate.

**Diagram file:** [Add image filename or link]

## Diagram 2: Caching and Retrieval Workflow

Suggested flow:

1. Receive request.
2. Check whether a valid cache entry can be reused.
3. If needed, retrieve relevant information.
4. Prepare context and call the model.
5. Return the response.
6. Apply appropriate cache update and freshness rules.

**Diagram file:** [Add image filename or link]

## Diagram 3: Amazon Bedrock Inference Workflow

Suggested flow:

1. Application submits an inference request.
2. Request uses the configured Amazon Bedrock interface and model.
3. Apply appropriate retry and connection-handling behavior.
4. Where configured and supported, Cross-Region Inference routes the request.
5. Application receives and evaluates the response.

**Diagram file:** [Add image filename or link]

## Important Note

These are suggested workflows for documentation. Update them to match the actual architecture, service configuration, and course material used.
