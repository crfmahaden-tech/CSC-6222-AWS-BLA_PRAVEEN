# Example JSON Configuration

## Overview

This file contains an example of a JSON-formatted AWS Identity and Access Management (IAM) policy.

## Example Policy

```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Effect": "Allow",
      "Action": "s3:ListBucket",
      "Resource": "*"
    }
  ]
}
```

## Explanation

- **Version:** Specifies the policy language version.
- **Statement:** Contains the permissions defined by the policy.
- **Effect:** `Allow` indicates that the specified action is permitted by this statement.
- **Action:** `s3:ListBucket` is the permission to list the objects in an S3 bucket.
- **Resource:** `*` applies the statement to all resources supported by the action. This is broad and should be narrowed where possible.

## Security Note

For a production policy, replace `"Resource": "*"` with the ARN of the specific S3 bucket, for example:

```json
"Resource": "arn:aws:s3:::your-bucket-name"
```

Replace `your-bucket-name` with the actual bucket name. Review the policy against the principle of least privilege before using it.

## Status

**Example only — review and customize before use.**
