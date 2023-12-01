[% IF patron.borrowernumber %]
<table id="ill-requests-patron-[% patron.borrowernumber | html %]">
[% ELSE %]
<table id="ill-requests">
[% END %]
 <thead>
 <tr id="ill_requests_header">
 <th scope="col">Request ID</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="author"         data-related-search-on="value">Tác giả</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="title"         data-related-search-on="value">Nhan đề</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="article_title" data-related-search-on="value">Article title</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="issue"         data-related-search-on="value">Kỳ</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="volume"        data-related-search-on="value">Tập</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="year"          data-related-search-on="value">Năm</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="pages"         data-related-search-on="value">Pages</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="type"          data-related-search-on="value">Request type</th>
 <th scope="col">Order ID</th>
 <th scope="col">Bạn đọc</th>
 <th scope="col">Bibliographic record ID</th>
 <th scope="col">Thư viện</th>
 <th scope="col">Trạng thái</th>
 <th scope="col" class="placed_formatted">Ngày đặt hàng</th>
 <th scope="col" class="updated_formatted">Ngày cập nhật</th>
 <th scope="col">Replied</th>
 <th scope="col" class="completed_formatted">Completed on</th>
 <th scope="col">Access URL</th>
 <th scope="col">Cost</th>
 <th scope="col">Price paid</th>
 <th scope="col">Bình luận</th>
 <th scope="col">OPAC notes</th>
 <th scope="col">Staff notes</th>
 <th scope="col">Backend</th>
 <th scope="col" class="actions"></th>
 </tr>
 </thead>
 <tbody id="illview-body">
 </tbody>
</table>