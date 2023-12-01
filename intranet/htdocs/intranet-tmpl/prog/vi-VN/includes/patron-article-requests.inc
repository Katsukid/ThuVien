[% USE Context %]
[% SET current_article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current' ) %]
[% IF current_article_requests.count > 0 %]
 <table id="article-requests-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="article-request-record-title anti-the">Record title</th>
 <th class="article-request-created_on psort">Ngày đặt hàng</th>
 <th class="article-request-title anti-the">Nhan đề</th>
 <th class="article-request-author">Tác giả</th>
 <th class="article-request-volume">Tập</th>
 <th class="article-request-issue">Kỳ</th>
 <th class="article-request-date">Thời gian</th>
 <th class="article-request-toc" title="Table of contents">TOC</th>
 <th class="article-request-pages">Pages</th>
 <th class="article-request-chapters">Chapters</th>
 <th class="article-request-notes">Ghi chú</th>
 <th class="article-request-format">Format</th>
 <th class="article-request-status">Trạng thái</th>
 <th class="article-request-branchcode">Thư viện nhận tài liệu</th>
 </tr>
 </thead>

 <tbody>
 [% FOREACH ar IN current_article_requests %]
 <tr>
 <td class="article-request-record-title">
 <a class="article-request-record-link-title" href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% ar.biblionumber | html %]">
 [% ar.biblio.title | html %]
 [% ar.item.enumchron | html %]
 </a>
 [% ar.biblio.author | html %]
 [% IF ar.itemnumber %] <em>(only [% ar.item.barcode | html %])</em>[% END %]
 </td>

 <td class="article-request-created_on">
 [% ar.created_on | $KohaDates %]
 </td>

 <td class="article-request-title">
 [% ar.title | html %]
 </td>

 <td class="article-request-author">
 [% ar.author | html %]
 </td>

 <td class="article-request-volume">
 [% ar.volume | html %]
 </td>

 <td class="article-request-issue">
 [% ar.issue | html %]
 </td>

 <td class="article-request-date">
 [% ar.date | html %]
 </td>

 <td class="article-request-toc">
 [% IF ar.toc_request %]<span>Có</span>[% END %]
 </td>

 <td class="article-request-pages">
 [% ar.pages | html %]
 </td>

 <td class="article-request-chapters">
 [% ar.chapters | html %]
 </td>

 <td class="article-request-patron-notes">
 [% ar.patron_notes | html %]
 </td>

 <td class="article-request-format">
 [% IF ar.format == 'PHOTOCOPY' %]<span>Sao chép</span>
 [% ELSIF ar.format == 'SCAN' %]<span>Scan</span>
 [% END %]
 </td>

 <td class="article-request-status">
 [% IF ar.status == 'PENDING' %]
 <span>Chờ duyệt</span>
 [% ELSIF ar.status == 'PROCESSING' %]
 <span>Processing</span>
 [% ELSIF ar.status == 'COMPLETED' %]
 <span>Completed</span>
 [% ELSIF ar.status == 'CANCELED' %]
 <span>Canceled</span>
 [% END %]
 </td>

 <td class="article-request-branchcode">
 [% ar.branch.branchname | html %]
 </td>
 </tr>
 [% END %]
 </tbody>
 </table>
 [% ELSE %]
 <span>Patron has no current article requests.</span>
 [% END %]
